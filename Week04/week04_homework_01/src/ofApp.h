#pragma once

#include "ofMain.h"
#include "ofxGui.h"


#define PINK 196, 0, 118
#define PURPLE 76, 0, 183
#define TEAL 24, 178, 198
#define BLUE 10, 144, 209

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
    
    ofEasyCam cam;
    ofSpherePrimitive sphere;
    ofShader shader;
    ofFbo fboSphere;
    
    ofShader shaderBlurX;
    ofShader shaderBlurY;
    
    ofFbo fboBlurOnePass;
    ofFbo fboBlurTwoPass;
    
    //sound
    ofSoundPlayer soundPlayer;
    
    
    //text
    float level;
    
    
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
    
    
    //kris color
    ofColor pink; //#define PINK 196, 0, 118
    ofColor purple; //#define PURPLE 76, 0, 183
    ofColor teal; //#define TEAL 24, 178, 198
    ofColor blue; //#define BLUE 10, 144, 209
    
    int oldR;
    int newR;
    int oldG;
    int newG;
    int oldB;
    int newB;
    
    float smoothSpeed;
    
};

