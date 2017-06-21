#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0, 0, 0);
    ofSetFrameRate(60);
    
//    positionX = 0.0;
    pmouseX = 0;
    pmouseY = 0;
}

//--------------------------------------------------------------
void ofApp::update(){ //描画ともなわない繰り返し
//    positionX += 1;
    
//    p0.update();
//    p1.update();
//    p2.update();
    for (int i = 0; i < 500; i++) {
        particles[i].update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
//    ofSetColor(0, 128, 255);
//    ofDrawCircle(positionX, ofGetHeight()/2, 50);

//    p0.draw();
//    p1.draw();
//    p2.draw();
    
    for (int i = 0; i < 500; i++) {
        particles[i].draw();
    }
    
    for (int i = 0; i < 500; i++) {
        Particle tmp = particles[i];
        
        for (int j = 0; j < 500; j++) {
            float d = sqrt((particles[j].xPos - tmp.xPos) * (particles[j].xPos - tmp.xPos) + (particles[j].yPos - tmp.yPos) * (particles[j].yPos - tmp.yPos)); //sqrt ルートの値
            if (d < 30) {
                ofDrawLine(tmp.xPos, tmp.yPos, particles[j].xPos, particles[j].yPos);
            }
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 'w') {
        ofBackground(255, 255, 255);
    }
    if (key == 'b') {
        ofBackground(0, 0, 0);
    }
    if (key == 'c') {
        ofBackground(ofRandom(255), ofRandom(255), ofRandom(255));
    }
    if (key == 'a') {
        for (int i = 0; i < 500; i++) {
            particles[i].xSpeed = ofRandom(-3, 3);
            particles[i].ySpeed = ofRandom(-3, 3);
            particles[i].radius = ofRandom(10);
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    for ( int i = 0; i < 500; i++) {
        particles[i].xPos += (ofGetWidth()/2/100 - x/100);
        particles[i].yPos += (ofGetHeight()/2/100 - y/100);
    }
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
