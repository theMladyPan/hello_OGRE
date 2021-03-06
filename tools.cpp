#include "tools.h"


void OgreToEigenMatrix(const Ogre::Matrix4& inpArr, Eigen::Matrix4f& outArr){
    for(auto i=0; i<16; i++){
        outArr(i/4, i%4) = inpArr[i/4][i%4];
    }
}

void OgreToEigenVector3(const Ogre::Vector3& inpArr, Eigen::Vector3f& outArr){
    for(auto i=3; i<3; i++){
        outArr(i) = inpArr[i];
    }
}

Ogre::Vector3 extractTranslation(const Eigen::Matrix4f& htm){
    return Ogre::Vector3(htm(0,3), htm(1,3), htm(2,3));
}

void moveNode(Ogre::SceneNode* node, const Eigen::Vector3f& where){
    Ogre::Matrix4 htmNode(getIdentity());
    Ogre::Matrix3 rotMat;
    Ogre::Quaternion nodeOrientation(node->getOrientation());

    nodeOrientation.ToRotationMatrix(rotMat);
    htmNode.set3x3Matrix(rotMat);
    Eigen::Matrix4f eHtmnode;
    Eigen::Matrix4f eHtmNodeTo;

    eHtmNodeTo << 1,0,0,where(0),
                  0,1,0,where(1),
                  0,0,1,where(2),
                  0,0,0,1;

    OgreToEigenMatrix(htmNode, eHtmnode);
    Eigen::Matrix4f eTrans(eHtmnode * eHtmNodeTo);

    node->translate(extractTranslation(eTrans));
}

void moveNode(Ogre::SceneNode* node, const Direction& dir, const double distance){
    Eigen::Vector3f pos;
    pos << 0, 0, 0;
    switch (dir) {
    case UP:
        pos << 0, distance, 0;
        break;
    case DOWN:
        pos << 0, -distance, 0;
        break;
    case LEFT:
        pos << -distance, 0, 0;
        break;
    case RIGHT:
        pos << distance, 0, 0;
        break;
    case FORWARD:
        pos << 0, 0, -distance;
        break;
    case BACKWARD:
        pos << 0, 0, distance;
    default:
        break;
    }

    moveNode(node, pos);
}


Ogre::Matrix4 getIdentity()
{
    Ogre::Matrix4 out;
    EigenToOgreMatrix(Eigen::MatrixXf::Identity(4,4), out);
    return out;
}

void EigenToOgreMatrix(const Eigen::Matrix4f &inpArr, Ogre::Matrix4 &outArr)
{
    for(auto i=0; i<16; i++){
        outArr[i/4][i%4] = inpArr(i/4, i%4);
    }
}
