#include "mytestapp.h"

MyTestApp::MyTestApp() : OgreBites::ApplicationContext("OgreTutorialApp"){
}

bool MyTestApp::mouseWheelRolled(const OgreBites::MouseWheelEvent& evt){
    switch (static_cast<int>(evt.y)){
    case 1:
        //whl up
        moveNode(camNode, FORWARD);
        break;
    case -1:
        // Whl dn
        moveNode(camNode, BACKWARD);
        break;
    default:
        break;
    }

    return true;
}

bool MyTestApp::mouseMoved(const OgreBites::MouseMotionEvent &evt)
{
    if(LMB){
        camNode->rotate(Ogre::Vector3(0,1,0),Ogre::Radian(angularSpeed * evt.xrel));
        camNode->rotate(Ogre::Vector3(1,0,0),Ogre::Radian(angularSpeed * evt.yrel));
    }else if (RMB) {
        if(evt.xrel != 0){
            moveNode(camNode,Eigen::Vector3f(-evt.xrel, 0, 0));
        }
        if(evt.yrel != 0){
            moveNode(camNode,Eigen::Vector3f(0, evt.yrel, 0));
        }

    } else {
        // do nothing for now
    }

    return true;
}


bool MyTestApp::mousePressed(const OgreBites::MouseButtonEvent& evt){
    // 1 lmb
    // 2 mmb
    // 3 rmb
    switch (static_cast<int>(evt.button)) {
    case 1:
        LMB = true;
        break;
    case 3:
        RMB = true;
    default:
        break;
    }

    return true;
}

bool MyTestApp::mouseReleased(const OgreBites::MouseButtonEvent &evt)
{
    LMB = false;
    RMB = false;

    return true;
}

bool MyTestApp::keyPressed(const OgreBites::KeyboardEvent& evt)
{
    // MODs:
    // ctrl 64
    // alt 256
    // shift 1

    switch (static_cast<int>(evt.keysym.mod)){
    case 64:
        // ctrl
        MOD = CTRL;
        break;
    case 256:
        MOD = ALT;
        break;
    case 1:
        MOD = SHIFT;
        break;
    default:
        break;
    }

    switch (evt.keysym.sym) {
    case OgreBites::SDLK_UP:
        moveNode(camNode, UP);
        break;
    case OgreBites::SDLK_DOWN:
        moveNode(camNode, DOWN);
        break;
    case OgreBites::SDLK_LEFT:
        moveNode(camNode, LEFT);
        break;
    case OgreBites::SDLK_RIGHT:
        moveNode(camNode, RIGHT);
        break;
    case OgreBites::SDLK_KP_MINUS:
        moveNode(camNode, BACKWARD);
        break;
    case OgreBites::SDLK_KP_PLUS:
        moveNode(camNode, FORWARD);
    default:
        break;
    }

    if (evt.keysym.sym == OgreBites::SDLK_ESCAPE)
    {
        getRoot()->queueEndRendering();
    }
    return true;
}

bool MyTestApp::keyReleased(const OgreBites::KeyboardEvent &evt)
{
    MOD = evt.keysym.mod;
    return true;
}



void MyTestApp::setup(void)
{
    // do not forget to call the base first
    OgreBites::ApplicationContext::setup();

    // register for input events
    addInputListener(this);
    // get a pointer to the already created root
    Ogre::Root* root = getRoot();
    scnMgr = root->createSceneManager();

    // register our scene with the RTSS
    Ogre::RTShader::ShaderGenerator* shadergen = Ogre::RTShader::ShaderGenerator::getSingletonPtr();
    shadergen->addSceneManager(scnMgr);
    // scnMgr->setAmbientLight(Ogre::ColourValue(.5, .5, .5));


    setupLight();
    setupCamera();

    // finally something to render
    //populateWithBalls();
    renderMolecule();
}

void MyTestApp::setupLight()
{
    // without light we would just get a black screen
    Ogre::Light* light = scnMgr->createLight("MainLight");
    lightNode = scnMgr->getRootSceneNode()->createChildSceneNode();
    lightNode->setPosition(0, 0, 1000);
    lightNode->attachObject(light);
}

void MyTestApp::setupCamera()
{
    // also need to tell where we are
    camNode = scnMgr->getRootSceneNode()->createChildSceneNode();
    camNode->setPosition(0, 0, 1000);
    camNode->lookAt(Ogre::Vector3(0, 0, -1), Ogre::Node::TS_PARENT);

    // create the camera
    Ogre::Camera* cam = scnMgr->createCamera("myCam");
    cam->setNearClipDistance(5); // specific to this sample
    cam->setAutoAspectRatio(true);
    camNode->attachObject(cam);

    // and tell it to render into the main window
    getRenderWindow()->addViewport(cam);
}

void MyTestApp::populateWithBalls()
{
    for (int i=0; i<1000; i++){
        entities.push_back(scnMgr->createEntity("sphere.mesh"));
        nodes.push_back(scnMgr->getRootSceneNode()->createChildSceneNode());
        nodes.back()->setPosition(2500-random()%5000, 2500-random()%5000, 2500-random()%5000);
        nodes.back()->attachObject(entities.back());
    }
}

void MyTestApp::renderMolecule()
{
    auto entity0(scnMgr->createEntity("sphere.mesh"));
    nodes.push_back(scnMgr->getRootSceneNode()->createChildSceneNode());
    nodes.back()->setPosition(0, 0, 0);
    nodes.back()->attachObject(entity0);
    for (auto i=0; i<100; i++){
        entities.push_back(scnMgr->createEntity("sphere.mesh"));
        nodes.push_back(nodes.back()->createChildSceneNode());
        nodes.back()->setPosition(200,0,0);
        nodes.back()->roll(Ogre::Radian(3.1416/12));
        nodes.back()->pitch(Ogre::Radian(3.1416/12));
        nodes.back()->attachObject(entities.back());
        // moveNode(nodes.back(),UP);
    }
}
