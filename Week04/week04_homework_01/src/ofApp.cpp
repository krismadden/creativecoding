#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    //kris' colors
    pink.set(196, 0, 118); //#define PINK 196, 0, 118
    purple.set(76, 0, 183); //#define PURPLE 76, 0, 183
    teal.set(24, 178, 198); //#define TEAL 24, 178, 198
    blue.set(10, 144, 209); //#define BLUE 10, 144, 209
    
    smoothSpeed = 0.9;
    
    oldR = blue.r;
    oldG = blue.g;
    oldB = blue.b;
    
    shader.load("shaders/noise");
    sphere.setRadius(80);
    sphere.setResolution(40);
    
    shaderBlurX.load("shaders/shaderBlurX");
    shaderBlurY.load("shaders/shaderBlurY");
    
    fboSphere.allocate(ofGetWidth(), ofGetHeight());
    fboBlurOnePass.allocate(ofGetWidth(), ofGetHeight());
    fboBlurTwoPass.allocate(ofGetWidth(), ofGetHeight());
    
    //
    
    // init of incrementing values
    //count = 0.0f;
    audioPan = 0.5f;
    //roll = 0.0f;
    // set background color
    background.set(blue);
    interp.set(blue);
    interpAmt = 0.0f;
    hue = background.getHue();
    
    // load song
    music.loadSound("song.mp3");
    music.setVolume(1.0f);
    music.play();
    music.setLoop(true);
    
    // FFT initialization
    fftSmoothed = new float[8192];
    for (int i = 0; i < 8192; i++){
        fftSmoothed[i] = 0;
    }
    nBandsToGet = 128;
    
    
    
    level = 100.0;
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    //added
    // interpolate speaker direction
    audioPanMax = 0.5f;
    if (audioPan <= audioPanMax)
        audioPan += 0.001f;
    music.setPan(audioPan);
    
    // interpolate between background colours
    if (interpAmt <= 1.0f)
        interpAmt += 0.01f;
    background.lerp(interp, interpAmt);
    
    // update the sound playing system:
    ofSoundUpdate();
    float* val = ofSoundGetSpectrum(nBandsToGet);
    avgSound = 0;
    
    // smooth fft and calc average volume
    for (int i = 0;i < nBandsToGet; i++){
        fftSmoothed[i] *= 0.96f;
        if (fftSmoothed[i] < val[i]) fftSmoothed[i] = val[i];
        avgSound += fftSmoothed[i];
    }
    
    // calculate average loudness of the music for "volume"
    avgSound /= nBandsToGet;
    
    // set new background based on fft "loudness" average
    //KRIS TRY TO CREATE EASING HERE BETWEEN THE COLORS
    if (avgSound > 0.07){ // pink
        //smoothX = mouseX;
        //newR = pink.r;
        //smoothX = smoothSpeed*smoothX + (1-smoothSpeed)*mouseX;
        //newR = smoothSpeed*newR + (1-smoothSpeed)*oldR;
        
//        newR = pink.r;
//        newG = pink.g;
//        newB = pink.b;
        
//        pink.r = smoothSpeed*pink.r + (1-smoothSpeed)*oldR;
//        pink.g = smoothSpeed*pink.g + (1-smoothSpeed)*oldG;
//        pink.b = smoothSpeed*pink.b + (1-smoothSpeed)*oldB;
//        interp.set(pink.r, pink.b, pink.g);
        
        newR = smoothSpeed*newR + (1-smoothSpeed)*oldR;
        newG = smoothSpeed*newG + (1-smoothSpeed)*oldG;
        newB = smoothSpeed*newB + (1-smoothSpeed)*oldB;
        interp.set(newR, newG, newB);
        
        oldR = pink.r;
        oldG = pink.g;
        oldB = pink.b;
    }
    else if (avgSound > 0.04){ // purple
//        newR = purple.r;
//        newG = purple.g;
//        newB = purple.b;
        
        newR = smoothSpeed*newR + (1-smoothSpeed)*oldR;
        newG = smoothSpeed*newG + (1-smoothSpeed)*oldG;
        newB = smoothSpeed*newB + (1-smoothSpeed)*oldB;
        interp.set(newR, newG, newB);
        
//        purple.r = smoothSpeed*purple.r + (1-smoothSpeed)*oldR;
//        purple.b = smoothSpeed*purple.b + (1-smoothSpeed)*oldG;
//        purple.g = smoothSpeed*purple.g + (1-smoothSpeed)*oldB;
//        interp.set(purple.r, purple.g, purple.b);
        
        oldR = purple.r;
        oldG = purple.g;
        oldB = purple.b;
    }
    else if (avgSound > 0.01){ //teal
//        newR = teal.r;
//        newG = teal.g;
//        newB = teal.b;
        
        newR = smoothSpeed*newR + (1-smoothSpeed)*oldR;
        newG = smoothSpeed*newG + (1-smoothSpeed)*oldG;
        newB = smoothSpeed*newB + (1-smoothSpeed)*oldB;
        interp.set(newR, newG, newB);
        
        oldR = teal.r;
        oldG = teal.g;
        oldB = teal.b;
        
    }
    else{
//        newR = blue.r;
//        newG = blue.g;
//        newB = blue.b;
        
        newR = smoothSpeed*newR + (1-smoothSpeed)*oldR;
        newG = smoothSpeed*newG + (1-smoothSpeed)*oldG;
        newB = smoothSpeed*newB + (1-smoothSpeed)*oldB;
        interp.set(newR, newG, newB);
        
        oldR = blue.r;
        oldG = blue.g;
        oldB = blue.b;
        
    }
    
//    newR = smoothSpeed*newR + (1-smoothSpeed)*oldR;
//    newG = smoothSpeed*newG + (1-smoothSpeed)*oldG;
//    newB = smoothSpeed*newB + (1-smoothSpeed)*oldB;
//    interp.set(newR, newG, newB);
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
    
    fboSphere.begin();
    ofClear(255,255,255, 0);
    ofSetColor(background);
    ofDisableDepthTest();
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    ofEnableDepthTest();
    cam.begin();
    shader.begin();
    shader.setUniform1f("time",ofGetElapsedTimef());
    shader.setUniform1f("u_avgSound", avgSound);
    sphere.drawWireframe();
    shader.end();
    cam.end();
    fboSphere.end();
    
    
    
    float blur = ofMap(mouseX, 0, ofGetWidth(), 0, 5, true);
    
    
    //text
    ofClear(0);
    ofSetColor(0);
    ofDrawBitmapString("avgSound " + std::to_string(avgSound), 100, 100);
    
    //----------------------------------------------------------
    fboBlurOnePass.begin();
    ofClear(255,255,255, 0);
    shaderBlurX.begin();
    shaderBlurX.setUniform1f("blurAmnt", blur);
    
    fboSphere.draw(0,0);
    
    
    shaderBlurX.end();
    
    fboBlurOnePass.end();
    
    //----------------------------------------------------------
    fboBlurTwoPass.begin();
    ofClear(255,255,255, 0);
    shaderBlurY.begin();
    shaderBlurY.setUniform1f("blurAmnt", blur);
    
    fboBlurOnePass.draw(0, 0);
    
    shaderBlurY.end();
    
    fboBlurTwoPass.end();
    
    //----------------------------------------------------------
    ofSetColor(ofColor::white);
    fboBlurTwoPass.draw(0, 0);
    
    
    
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    shader.load("shaders/noise");
    shaderBlurX.load("shaders/shaderBlurX");
    shaderBlurY.load("shaders/shaderBlurY");
    
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

