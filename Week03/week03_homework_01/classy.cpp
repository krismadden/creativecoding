#include "classy.h"

//--------------------------------------------------------------
void classy::setup(){
    pos = ofPoint(ofRandom(1024), ofRandom(768));
    color.set(ofRandom(50,220),ofRandom(100,230),ofRandom(0,255));
    size = ofRandom(10, 60);
    
    vel = ofVec2f( ofRandom(-5, 5), ofRandom(-5, 5));
    
     ofAddListener(ofEvents().mousePressed, this, &classy::mousePressed);
}

//--------------------------------------------------------------
void classy::update(){
    pos += vel; // add velocity to position
    vel *= .99; //quick way to create friction
    
}

//--------------------------------------------------------------
void classy::draw(){
    ofSetColor(color);
    ofDrawCircle(pos, size); // == ofDrawCircle(pos.x, pos.y, 40);
    
}

void classy::mousePressed(ofMouseEventArgs& _mouse){
    
    ofLog() << "mouse pressed from cool ball: " << _mouse.x;
    
    mouse.set(_mouse.x,_mouse.y);
    pos = mouse;
    vel = ofVec2f( ofRandom(-5, 5), ofRandom(-5, 5));
}

