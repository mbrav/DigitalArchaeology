#include "ofApp.h"

 //           _
 //  ___  ___| |_ _   _ _ __
 // / __|/ _ \ __| | | | '_ \
 // \__ \  __/ |_| |_| | |_) |
 // |___/\___|\__|\__,_| .__/
 //                    |_|

void ofApp::setup() {

  ofSetLogLevel(OF_LOG_VERBOSE);
  ofBackground(130);

  ofDisableArbTex(); // we need GL_TEXTURE_2D for our model coords.

  ofBackground(0, 0, 0);

  camera.setFarClip(20000);
  // camera.move(0,0,15000);

  scene = 1; // set scene to one

  for (unsigned int i = 0; i < modelNum; i++) {

    ofModel myModelTemp;
    myModelTemp.setup("m" + ofToString(i%modelFiles+1) + ".stl");
    myModelTemp.setPos(ofVec3f(ofRandom(-100, 100), ofRandom(-100, 100), ofRandom(-100, 100)));
    models.push_back(myModelTemp);

  }

}

 //                  _       _
 //  _   _ _ __   __| | __ _| |_ ___
 // | | | | '_ \ / _` |/ _` | __/ _ \
 // | |_| | |_) | (_| | (_| | ||  __/
 //  \__,_| .__/ \__,_|\__,_|\__\___|
 //       |_|

void ofApp::update() {

  // int ran = (int)ofRandom(0, modelNum);
  // models[ran].disolve(0.01);
  // models[ran].vDisplace();

  for (unsigned int i = 0; i < modelNum; i++) {
    models[i].rot.x += 0.05*i;
    models[i].rot.y += 0.08*i;
    models[i].rot.z += 0.07*i;

    models[i].pos.x = models[i].initPos.x * cos(ofGetElapsedTimeMillis()/1000.1);
    models[i].pos.y = models[i].initPos.y * sin(ofGetElapsedTimeMillis()/1000.1);
    models[i].pos.z = models[i].initPos.z * sin(ofGetElapsedTimeMillis()/1000.1)-cos(ofGetElapsedTimeMillis()/1000.1);
  }

  loop++;
}

 //      _
 //   __| |_ __ __ ___      __
 //  / _` | '__/ _` \ \ /\ / /
 // | (_| | | | (_| |\ V  V /
 //  \__,_|_|  \__,_| \_/\_/

void ofApp::draw() {

  if (scene == 1) {
    scene1();
  } else if (scene == 2) {
    scene2();
  }

  ofDrawBitmapStringHighlight(titleString, 20, ofGetHeight()-270, ofColor(40), ofColor(210));
  ofDrawBitmapStringHighlight(textString, 20, ofGetHeight()-250, ofColor(210), ofColor(40));

  // ofDrawBitmapStringHighlight("SCENE I " + ofToString(ofGetFrameRate(), 2), ofGetWidth()/2-40, ofGetHeight()/2-30, ofColor(200), ofColor(50));

}

void ofApp::scene1() {
  titleString = "SCENE I — The Sky";
  textString = " When we take a glimpse into the night sky, \n most of us rarely realize that \n  we are looking at history. \n Whatever we see in the night sky, is a collection of photons that \n traveled for thousands and millions of years from their point of origin. \n The photons coming from Alpha Centauri for example, which is our \n closest neighboring stellar system, \n is already 4.3 years old by the time it reaches our telescopes. \n When we look at the center of our galaxy, we see light that is 27,000 years old. \n When we observe Andromeda, our neighboring galaxy, we see light that is 2.5 million years old. \n Our night sky is filled with the cosmic past, and the gigabytes of data collected by all kinds of telescopes, \n have yet to be 'excavated' and reveal an alien civilization that may be lurking among the data. \n The sky, can be considered a opaque sediment that you can see through, and \n  observe the timeline of the universe's history. \n Just by looking at the sky, we become 'observer archeologists' \n  who are engaged in an act of excavating the past.";

  ofBackground(0, 0, 0, 255);
  ofSetColor(200, 200, 200, 255);
  camera.begin();

  ofEnableDepthTest();
  // light.enable();
  ofEnableSeparateSpecularLight();

  // models[0].draw();

  for (unsigned int i = 0; i < modelNum; i++) {

    models[i].draw();

  }

  ofDisableDepthTest();
  light.disable();
  ofDisableLighting();

  camera.end();

  ofSetColor(0, 0, 0);
}


void ofApp::scene2() {
  titleString = "SCENE II — The Light";
  textString = "jdl;skfjg;lsdjfgl;j";

  ofBackground(255, 255, 255, 255);
  ofSetColor(20, 20, 20, 255);
  camera.begin();

  ofEnableDepthTest();
  // light.enable();
  ofEnableSeparateSpecularLight();

  // models[0].draw();

  for (unsigned int i = 0; i < modelNum; i++) {

    models[i].draw();

  }

  ofDisableDepthTest();
  light.disable();
  ofDisableLighting();

  camera.end();

  ofSetColor(255, 255, 255);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
  if (key == 'f') ofToggleFullscreen();
  if (key == '1') scene = 1;
  if (key == '2') scene = 2;
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {}
