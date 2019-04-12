#ifndef TOOLS_H
#define TOOLS_H

#include <iostream>
#include <Ogre.h>
#include <OGRE/Bites/OgreApplicationContext.h>
#include <Eigen/Eigen>

enum Direction{
    UP,
    DOWN,
    LEFT,
    RIGHT,
    FORWARD,
    BACKWARD
};

void OgreToEigenMatrix(const Ogre::Matrix4& inpArr, Eigen::Matrix4f& outArr);
void OgreToEigenVector3(const Ogre::Vector3& inpArr, Eigen::Vector3f& outArr);
Ogre::Vector3 extractTranslation(const Eigen::Matrix4f& htm);

void moveNode(Ogre::SceneNode* node, const Eigen::Vector3f& where);
void moveNode(Ogre::SceneNode* node, const Direction& dir);

#endif // TOOLS_H
