#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include <math.h>

enum Scenes{
    IDLE,
    SKY_SCENE,
    SUN_SCENE,
    PHOTO
};

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
    
    //shape?
        float r(float theta, float a, float b, float m, float n1, float n2, float n3);
        float t;
    
        ofxFloatSlider This;
        ofxFloatSlider That;
        ofxFloatSlider TheOther;
    
    //hide captions
        bool hidden;
    
        Scenes currentScene;
        string scenenumber;
        ofColor scenecolor;
		
        string fontname;
        ofTrueTypeFont font0;
        ofTrueTypeFont font1;
        ofTrueTypeFont font2;
        ofTrueTypeFont font3;
        ofTrueTypeFont font4;
    
        ofShader shader;
        ofShader shader1;
        ofShader shader2;
    
    
        // Audio
        ofSoundPlayer music;
        float audioPan, audioPanMax;
        float avgSound;
        float* fftSmoothed;
        int nBandsToGet;
    
        // Interpolated values
        float count;
        float roll;
        ofColor background;
        //ofColor rainbow;
        float hue;
        ofColor interp;
        float interpAmt;
    
        ofxFloatSlider red;
        ofxFloatSlider green;
        ofxFloatSlider blue;
        ofxPanel gui;
};
