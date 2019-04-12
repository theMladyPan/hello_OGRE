#ifndef MYTESTAPP_H
#define MYTESTAPP_H

#include <Ogre.h>
#include <OGRE/Bites/OgreApplicationContext.h>
#include <Eigen/Eigen>
#include "tools.h"

class MyTestApp : public OgreBites::ApplicationContext, public OgreBites::InputListener{
public:
    MyTestApp();
    void setup(void);
    bool keyPressed(const OgreBites::KeyboardEvent& evt);
    bool mousePressed(const OgreBites::MouseButtonEvent& evt);
    bool mouseReleased(const OgreBites::MouseButtonEvent &evt);
    bool mouseWheelRolled(const OgreBites::MouseWheelEvent& evt);
    bool mouseMoved(const OgreBites::MouseMotionEvent &evt);
private:
    Ogre::SceneManager* scnMgr;
    Ogre::SceneNode* lightNode;
    Ogre::SceneNode* camNode;

    bool LMB;
    bool RMB;
};

#endif // MYTESTAPP_H
