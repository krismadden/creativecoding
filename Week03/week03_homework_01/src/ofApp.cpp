#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    
    //vector
    
//    classyasfuck.push_back(classy()); //push_back adds something onto the end
//    classyasfuck[0].setup();
//    classyasfuck.push_back(classy()); //push_back adds something onto the end
//    classyasfuck[1].setup();
//    classyasfuck.push_back(classy()); //push_back adds something onto the end
//    classyasfuck[2].setup();
    
    for(int i=0; i<1; i++){
        classyasfuck.push_back(classy()); //push_back adds something onto the end
        classyasfuck[classyasfuck.size()-1].setup();
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    //vector
    //adds the motion
    for(int i=0; i<classyasfuck.size(); i++){
        classyasfuck[i].update();
    }
    
//    for(int i=0; i<10; i++){
//        classyasfuck[i].update();
//    }
    
//    for(int i=classyasfuck.size(); i>0; i--){
//        classyasfuck[i].update();
//    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    //vector
    for(int i=0; i<classyasfuck.size(); i++){
        classyasfuck[i].draw();
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
