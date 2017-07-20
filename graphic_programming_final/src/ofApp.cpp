#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(235, 235, 235);
    ofSetCircleResolution(64);
    
    ofSetFrameRate(60);
    
    pmouseX = 0;
    pmouseY = 0;
    
    midi.setup();
    
    gui.setup("KORG nanoKONTROL2");
    gui.add(knob[0].setup("knob1", 0, 0, 127));
    gui.add(knob[1].setup("knob2", 0, 0, 127));
    gui.add(knob[2].setup("knob3", 0, 0, 127));
    gui.add(knob[3].setup("knob4", 0, 0, 127));
    gui.add(knob[4].setup("knob5", 0, 0, 127));
    gui.add(knob[5].setup("knob6", 0, 0, 127));
    gui.add(knob[6].setup("knob7", 0, 0, 127));
    gui.add(knob[7].setup("knob8", 0, 0, 127));
    
    gui.add(slider[0].setup("Slider1", 0, 0, 127));
    gui.add(slider[1].setup("Slider2", 0, 0, 127));
    gui.add(slider[2].setup("Slider3", 0, 0, 127));
    gui.add(slider[3].setup("Slider4", 0, 0, 127));
    gui.add(slider[4].setup("Slider5", 0, 0, 127));
    gui.add(slider[5].setup("Slider6", 0, 0, 127));
    gui.add(slider[6].setup("Slider7", 0, 0, 127));
    gui.add(slider[7].setup("Slider8", 0, 0, 127));

}

//--------------------------------------------------------------
void ofApp::update(){
    midi.update();
    
    for (int j = 0; j < 8; j++) {
        knob[j] = midi.knobs[j];
        slider[j] = midi.sliders[j];
    }
    
    for (int i = 0; i < 500; i++) {
        particles[i].update();
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    gui.draw();
    ofSetColor(slider[0] * 2, slider[1] * 2, slider[2] * 2);
    ofDrawCircle(ofGetWidth() / 2, ofGetHeight() / 2, knob[0] * 2);
    
    ofSetColor(slider[1] * 2, slider[2] * 2, slider[0] * 2);
//    for (int i = 0; i < knob[1]; i++) {
//        for (int j = 0; i < knob[1]; j++) {
//            ofPushMatrix();
//            ofTranslate(i, j);
//            ofDrawRectangle(knob[1], knob[1], 20, 20);
//            ofPopMatrix();
//        }
//    }
    ofDrawRectangle(ofGetWidth()/2 - knob[1]/2, ofGetHeight()/2 - knob[1]/2, knob[1], knob[1]);
    
    for (int i = 0; i < knob[2]; i++) {
        particles[i].draw();
    }
    
    for (int i = 0; i < knob[2]; i++) {
        Particle tmp = particles[i];
        
        for (int j = 0; j < knob[2]; j++) {
            float d = sqrt((particles[j].xPos - tmp.xPos) * (particles[j].xPos - tmp.xPos) + (particles[j].yPos - tmp.yPos) * (particles[j].yPos - tmp.yPos)); //sqrt ルートの値
            if (d < 30) {
                ofDrawLine(tmp.xPos, tmp.yPos, particles[j].xPos, particles[j].yPos);
            }
        }
    }
    
    ofSetColor(slider[2] * 2, slider[0] * 2, slider[1] * 2);
    ofDrawCone(ofGetWidth()/2, ofGetHeight()/2, knob[3], knob[3]);
    
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
