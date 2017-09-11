#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundColor(113, 97, 163);
    ofSetCircleResolution(20);
    
    //initialize values here
    smoothX = mouseX;
    smoothY = mouseY;
    
    smoothSpeed = 0.9;
    
    angle2=0;
    
    
    //gui
    
    
    gui.setup();
    gui.add(radius.setup("radius", 140, 10, 300));
    
    
    x1 = 100; // how far from left
    x2 = x1 + 400; // how long
    y1 = 60; //how far from top
    y2 = y1;
    moveX = x1;
    dir = 1;

}

//--------------------------------------------------------------
void ofApp::update(){
    smoothX = smoothSpeed*smoothX + (1-smoothSpeed)*mouseX;
    smoothY = smoothSpeed*smoothY + (1-smoothSpeed)*mouseY;
    float angle = ofMap(mouseX,0,ofGetWidth(), 0, TWO_PI);
    // circle1 =  radius * cos(angle);
    x =  50 * cos(angle);
    y =  50 * sin(angle);
    
    //increase angle so it changes rotation (.01 because we are in radians)
    angle2 += .01;
    
}

//--------------------------------------------------------------
void ofApp::draw(){

    
    
//    t += 0.01 * dir;
//    if (t <= 0 || t >= 1) dir *= -1;
//    
//    pct = pow(t,5.5);
//    
//    //moveX = moveX + .1;
//    
//    moveX = (1-pct) * x1 + pct * x2;
//    
//    if(moveX == x2){
//        moveX = x1;
//    }
//    
//    ofDrawLine(x1, y1, x2, y2);
//    ofDrawCircle(moveX, y1, 10);
    
    
    drawMotion(0,pow(t,5.5), "pow(t,5.5)");
    
    drawMotion(50,t*t*t, "t*t*t");

    drawMotion(100, -1 * (sqrt(1 - t * t) - 1), "-1 * (sqrt(1 - t * t) - 1)");
    
    drawMotion(150, sin(t / 1 * (M_PI * 0.5)), "sin(t / 1 * (M_PI * 0.5))");
    
}


void ofApp::drawMotion(int top, float math, string label){
    
    y1 = 60 + top;
    y2 = y1;
    
    t += 0.006 * dir;
    if (t <= 0 || t >= 1) dir *= -1;
    
    pct = math;
    
    //moveX = moveX + .1;
    
    moveX = (1-pct) * x1 + pct * x2;
    
    if(moveX == x2){
        moveX = x1;
    }
    
    ofDrawLine(x1, y1, x2, y2);
    ofDrawCircle(moveX, y1, 10);
    
    ofDrawBitmapStringHighlight(label, x2 + 50, y2);
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
