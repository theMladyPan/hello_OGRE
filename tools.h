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

enum Mods{
    CTRL,
    ALT,
    SHIFT
};

void OgreToEigenMatrix(const Ogre::Matrix4& inpArr, Eigen::Matrix4f& outArr);
void EigenToOgreMatrix(const Eigen::Matrix4f& inpArr, Ogre::Matrix4& outArr);
void OgreToEigenVector3(const Ogre::Vector3& inpArr, Eigen::Vector3f& outArr);

Ogre::Vector3 extractTranslation(const Eigen::Matrix4f& htm);
Ogre::Matrix4 getIdentity();

void moveNode(Ogre::SceneNode* node, const Eigen::Vector3f& where);
void moveNode(Ogre::SceneNode* node, const Direction& dir, const double distance = 10);

#endif // TOOLS_H
