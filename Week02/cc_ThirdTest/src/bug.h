#ifndef _BUG // if this class hasn't been defined, the program can define it
#define _BUG // by using this if statement you prevent the class to be called more than once which would confuse the compiler

#include "ofMain.h" // we need to include this to have a reference to the openFrameworks framework
class bug {
    
public: // place public functions or variables declarations here
    
    // methods, equivalent to specific functions of your class objects
    void setup();	// setup method, use this to setup your object's initial state
    void update(float smoothSpeed1);  // update method, used to refresh your objects properties
    void draw();    // draw method, this where you'll do the object's drawing

    
    void mouseMoved(ofMouseEventArgs& mouse);

    
    // variables
    ofPoint mouse;
    
    float x;        // position
    float y;
    float speedY;   // speed and direction
    float speedX;
    int dim;        // size
    ofColor color;  // color using ofColor type
    
    
    //mouse
    float Mx;
    float My;
    
    float smoothX1;
    float smoothY1;
    
    float smoothSpeed1;
    
private: // place private functions or variables declarations here
}; // don't forget the semicolon!
#endif
