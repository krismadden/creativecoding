#include "bug.h"






void bug::setup(){
    //ofAddListener(
    ofAddListener(ofEvents().mouseMoved, this, &bug::mouseMoved);
    
    
    x = ofRandom(0, ofGetWidth());      // give some random positioning
    y = ofRandom(0, ofGetHeight());
    
    speedX = ofRandom(-1, 1);           // and random speed and direction
    speedY = ofRandom(-1, 1);
    
    dim = 20;
    
    color.set(ofRandom(255),ofRandom(255),ofRandom(255)); // one way of defining digital color is by addressing its 3 components individually (Red, Green, Blue) in a value from 0-255, in this example we're setting each to a random value
    
    //mouse
    
//    smoothX1 = mouse.x;
//    smoothY1 = mouse.y;
    
    smoothSpeed1 = 0.8;
    
    
    
    
}


void bug::update(float smoothSpeed1){
    if(x < 0 ){
        x = 0;
        speedX *= -1;
    } else if(x > ofGetWidth()){
        x = ofGetWidth();
        speedX *= -1;
    }
    
    if(y < 0 ){
        y = 0;
        speedY *= -1;
    } else if(y > ofGetHeight()){
        y = ofGetHeight();
        speedY *= -1;
    }
    
    x+=speedX;
    y+=speedY;
    
    
    
    //mouse
    
    smoothX1 = smoothSpeed1*smoothX1 + (1-smoothSpeed1)*mouse.x;
    smoothY1 = smoothSpeed1*smoothY1 + (1-smoothSpeed1)*mouse.y;
    float angle = ofMap(mouse.x,0,ofGetWidth(), 0, TWO_PI);
    Mx =  50 * cos(angle);
    My =  50 * sin(angle);
}

void bug::draw(){
    ofSetColor(color);
    ofDrawCircle(x, y, dim);
    
    
    
    // mouse
    
    float angle = atan2(mouse.y-smoothY1, mouse.x-smoothX1);
    //convert radians to degrees
    angle = ofRadToDeg(angle);
    
    ofSetRectMode(OF_RECTMODE_CENTER);
    
    ofPushMatrix();
    
    ofTranslate(smoothX1, smoothY1);
    ofRotate(angle);
    ofSetColor(107, 109, 109);
    ofDrawRectangle(0, 0, 60, 50);
    
    ofPopMatrix();
    
}




void bug::mouseMoved(ofMouseEventArgs& _mouse){
    
    //ofLog() << "mouse pressed from cool ball: " << _mouse.x;
    
    mouse.set(_mouse.x,_mouse.y);
    
//    smoothX1 = mouse.x;
//    smoothY1 = mouse.y;

}



