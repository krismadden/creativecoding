#include "ofApp.h"

//string fontname;
//ofColor scenecolor;

//--------------------------------------------------------------
void ofApp::setup(){
    shader.load("","shader.frag");
    shader2.load("","shader2.frag");
    shader1.load("","shader1.frag");
    
    currentScene = IDLE;
    scenenumber = "1";
    scenecolor.r=134;
    scenecolor.g=204;
    scenecolor.b=198;
    //fontname = "King-Basil-Lite.ttf";
    
    
    font0.load("King-Basil-Lite.ttf", 30);
    
    font1.load("King-Basil-Lite.ttf", 30);
    font2.load("Hangar Nine.otf", 30);
    font3.load("Heroic.ttf", 30);
    font4.load("zorque.ttf", 30);
    
    // init of incrementing values
    audioPan = 0.5f;
    interpAmt = 0.0f;
    hue = background.getHue();
    
    // load song
    music.loadSound("song.mp3");
    music.setVolume(0.0f);
    music.play();
    music.setLoop(true);
    
    // FFT initialization
    fftSmoothed = new float[8192];
    for (int i = 0; i < 8192; i++){
        fftSmoothed[i] = 0;
    }
    nBandsToGet = 128;
    
    gui.setup();
    gui.add(red.setup("red", 0, 0, 255));
    gui.add(green.setup("green", 0, 0, 255));
    gui.add(blue.setup("blue", 0, 0, 255));
    

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
    
   
    avgSound /= nBandsToGet;
    
    if(currentScene == IDLE){
        // updates for idle scene
        music.setVolume(0.0f);
        font0.load("King-Basil-Lite.ttf", 30);
    }else if(currentScene == SKY_SCENE){
        // updates for sky scene
        music.setVolume(0.0f);
        font0.load("Hangar Nine.otf", 30);
    }else if(currentScene == SUN_SCENE ){
        // updates for sun scene
        music.setVolume(1.0f);
        font0.load("Heroic.ttf", 30);
    }else if(currentScene == PHOTO ){
        // updates for sun scene
        music.setVolume(0.0f);
        font0.load("zorque.ttf", 30);
        
    }
    
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    

    // draws for each scene:
    
    if(currentScene == IDLE){
        scenenumber = "1";
        ofBackground(red, green, blue);
        ofSetColor(255);
        //ofDrawBitmapString("Idle mode: Press keys 1-4 to change.", 100, 100);
        font1.drawString("Press keys 1-4 to change.", 100, 100);
        scenecolor.r=134;
        scenecolor.g=204;
        scenecolor.b=198;
        
        //how do i move this down?!?!?!
        gui.draw();
    
    }else if(currentScene == SKY_SCENE){
        scenenumber = "2";
        ofBackgroundGradient( ofColor(66, 229, 244), ofColor(255,255,255) );
        scenecolor.r=255;
        scenecolor.g=216;
        scenecolor.b=0;
        
        int rectH = ofGetHeight()/2;
        int rectW = 5;
        
        shader1.begin();
        shader1.setUniform2f("u_resolution1", rectW, rectH);
        for(int i = -5; i < ofGetWidth(); i+= 10){
            ofDrawRectangle(i, 0, rectW, rectH);
            //looks cool: i/1.9, i/2,
            shader1.setUniform1f("u_time1", ofGetElapsedTimef() - pow((i+1000), 0.3));
        }
        shader1.end();

        shader2.begin();
        shader1.setUniform2f("u_resolution1", rectW, rectH - 0);
                for(int i = -5; i < ofGetWidth(); i+= 10){
                    ofDrawRectangle(i, 384, rectW, rectH);
                    //looks cool: i/1.9, i/2,
                    shader1.setUniform1f("u_time1", ofGetElapsedTimef() - pow((i+1000), 0.3));
                }
        shader2.end();
        ofSetColor(255, 216, 0);
        font2.drawString("Press keys 1-4 to change.", 100, 100);
        
    }else if(currentScene == SUN_SCENE ){
        scenenumber = "3";
        ofBackgroundGradient(ofColor(255, 252, 104), ofColor(255, 68, 227) );
        ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2, pow(2 + avgSound * 100, 2.5));
         ofSetColor(255);
        font3.drawString("Press keys 1-4 to change.", 100, 100);
        scenecolor.r=0;
        scenecolor.g=0;
        scenecolor.b=0;
    }else if(currentScene == PHOTO){
        scenenumber = "4";
         ofSetColor(26,2,142);
        ofBackgroundGradient(ofColor(40,100,240), ofColor(200,150,230));
        //font4.drawString("Press keys 1-4 to change.", 100, 100);
        //ofSetColor(40,100,240);
       
        //ofDrawRectangle(150, 150, 5, 200);
        
        
    
        
        
        shader.begin();
            int rectW = ofGetWidth();
            int rectH = 5;
            shader.setUniform2f("u_resolution", rectW, rectH);
           // shader.setUniform1f("u_time", ofGetElapsedTimef());
            for(int i = 0; i < ofGetHeight(); i+= 10){
                ofDrawRectangle(0, i, rectW, rectH);
                float calc = ofGetElapsedTimef() - i;
                //looks cool: i/1.9, i/2,
                shader.setUniform1f("u_time", ofGetElapsedTimef() - (i/1.9));
            }
        shader.end();
        
        font4.drawString("Press keys 1-4 to change.", 100, 100);
        scenecolor.r=26;
        scenecolor.g=2;
        scenecolor.b=142;
    }
    
    
    ofSetColor(scenecolor);
    font0.drawString("SCENE: " + scenenumber, 700, 100);
    
    //ofDrawBitmapString("avgSound " + std::to_string(avgSound), 300, 300);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    shader.load("","shader.frag");
    
    
    // use key press to change scenes and make any operations that
    // only need to happen on change (not update or draw )
    switch(key){
        case '1':
            currentScene = IDLE;
            break;
        case '2':
            currentScene = SKY_SCENE;
            break;
        case '3':
            currentScene = SUN_SCENE;
            ofSetCircleResolution(100);
            break;
        case '4':
            currentScene = PHOTO;
            break;
        case 'f':
            ofToggleFullscreen();
            break;
    }
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
