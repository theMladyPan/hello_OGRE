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
    void setupLight();
    void setupCamera();

    void populateWithBalls();
    void renderMolecule();

    bool keyPressed(const OgreBites::KeyboardEvent& evt);
    bool keyReleased(const OgreBites::KeyboardEvent &evt);
    bool mousePressed(const OgreBites::MouseButtonEvent& evt);
    bool mouseReleased(const OgreBites::MouseButtonEvent &evt);
    bool mouseWheelRolled(const OgreBites::MouseWheelEvent& evt);
    bool mouseMoved(const OgreBites::MouseMotionEvent &evt);
private:
    Ogre::SceneManager* scnMgr;
    Ogre::SceneNode* lightNode;
    Ogre::SceneNode* camNode;

    bool LMB = false;
    bool RMB = false;
    int MOD = 0;

    double scrollSpeed = 30;
    double angularSpeed = 0.002;

    std::vector<Ogre::Entity*> entities;
    std::vector<Ogre::SceneNode*> nodes;
};

#endif // MYTESTAPP_H
