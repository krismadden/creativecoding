#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundColor(172, 225, 229);
    ofSetCircleResolution(50);
    
    //initialize values here
    smoothX = mouseX;
    smoothY = mouseY;
    
    smoothSpeed = 0.9;
    
    
//    mybug1.setup(); // calling the object's setup method
//    mybug2.setup();
//    mybug3.setup();
//    mybug4.setup();
//    mybug5.setup();
    
    for(int i=0; i<NBUGS; i++){
        mybug[i].setup();
    }

}

//--------------------------------------------------------------
void ofApp::update(){
    smoothX = smoothSpeed*smoothX + (1-smoothSpeed)*mouseX;
    smoothY = smoothSpeed*smoothY + (1-smoothSpeed)*mouseY;
    float angle = ofMap(mouseX,0,ofGetWidth(), 0, TWO_PI);
    x =  50 * cos(angle);
    y =  50 * sin(angle);
    

    
//    mybug1.update(mouseX, mouseY); // calling the object's update method
//    mybug2.update();
//    mybug3.update();
//    mybug4.update();
//    mybug5.update();
    
    
    //can pass it in 
    for(int i=0; i<NBUGS; i++){
        mybug[i].update(i * 0.1);
        mybug[i].setup();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
   

    float angle = atan2(mouseY-smoothY, mouseX-smoothX);
    //convert radians to degrees
    angle = ofRadToDeg(angle);
    
    ofSetRectMode(OF_RECTMODE_CENTER);
    
    ofPushMatrix();

        ofTranslate(smoothX, smoothY);
        ofRotate(angle);
        ofSetColor(107, 109, 109);
        //ofDrawRectangle(0, 0, 60, 50);
        
    ofPopMatrix();
    
    
//    mybug1.draw(); // call the draw method to draw the object
//    mybug2.draw();
//    mybug3.draw();
//    mybug4.draw();
//    mybug5.draw();
    
    for(int i=0; i<NBUGS; i++){
        mybug[i].draw();
            //mybug[i].setup(mouseX, mouseY);
    }
    
   
    
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
