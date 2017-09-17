#pragma once

#include "ofMain.h"
#include "bug.h"

#define NBUGS 10

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
        //data types:
        //int : integer (-1,0,2)
        //float: decimals (-2.93, 2.0)
        //string : text ("hello world")
        //bool : true/false
    
    
    //global variables that exhist throughout the application are declared here in the header file
    //these are just declared here and will be initalized in the setup
        float x;
        float y;
    
        float smoothX;
        float smoothY;
    
        float smoothSpeed;
    
    
    
    
//    bug mybug1;
//    bug mybug2;
//    bug mybug3;
//    bug mybug4;
//    bug mybug5;
    
    bug mybug[NBUGS];
};
