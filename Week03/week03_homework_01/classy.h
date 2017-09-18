
#pragma once

#include "ofMain.h"

class classy{
public: //we can call them externally in ofApp. private: can only be called internally within class.
    void setup();
    void update();
    void draw();
    
    ofPoint pos;  //allows us to keep an x,y value in one variable
    
    ofColor color;  // color using ofColor type
    
    int size;
    
    ofVec2f vel; //a vector vector now
    
    // variables
    ofPoint mouse;
    
    void mousePressed(ofMouseEventArgs& mouse);
    

};
