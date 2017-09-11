#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundColor(220,220,255);
    ofSetCircleResolution(50);
    
    //initialize values here
    smoothX = mouseX;
    smoothY = mouseY;
    
    smoothSpeed = 0.9;
    
    angle2=0;
    
    
    //gui
    
    
    gui.setup();
    gui.add(radius.setup("radius", 140, 10, 300));

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
    //ofDrawCircle(smoothX, smoothY, 40);
    
//    ofFill();
//    ofSetColor(100, 200, 30);
//    ofDrawRectRounded(40, 40, 50, 50, 10);
    
    
    //gui
    ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2, radius);
    gui.draw();
    
    
    
    
    ofNoFill();
    ofSetColor(200, 140, 100);
    ofDrawCircle(100, 100, 40);
    
    ofFill();
    ofSetColor(100, 150, 50);
    ofDrawCircle(100+x, 100+y, 10);
    
    ofSetColor(215, 100, 255);
    ofDrawLine(100, 100, 100+x, 100+y);

    float angle = atan2(mouseY-smoothY, mouseX-smoothX);
    //convert radians to degrees
    angle = ofRadToDeg(angle);
    
    ofSetRectMode(OF_RECTMODE_CENTER);
    
    ofPushMatrix();

        ofTranslate(smoothX, smoothY);
        ofRotate(angle);
        ofSetColor(10, 200, 50);
        //ofDrawRectangle(0, 0, 60, 50);
        
    ofPopMatrix();
    
    ofNoFill();
    //draw big circle
    int bigX = ofGetWidth()/2;
    int bigY = ofGetHeight()/2;
    //int radius = 100;
    ofDrawCircle(bigX, bigY, radius);
    
    //draw small circle
    float smX = bigX + radius * cos(angle2);
    float smY = bigY + radius * sin(angle2);
    ofDrawCircle(smX, smY, 10);
    
    //line
    
    ofDrawLine(bigX, bigY, smX, smY);
    
    
    //gui
    
   
    
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
