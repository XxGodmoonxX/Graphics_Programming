#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    //GUI
    gui.setup();
    gui.add(toggle_0.setup("toggle 0", true));
    gui.add(fslider_0.setup("slider_0", 50.0, 0.0, 100.0));
    gui.add(cslider_0.setup("color",
                            ofColor(200, 200, 200),
                            ofColor(0, 0, 0),
                            ofColor(255, 255, 255)));
    gui.add(medama_num.setup("medama_num", 100, 0, medama_max_num));
    gui.add(cslider_1.setup("backgroundColor",
                            ofColor(100, 100, 100),
                            ofColor(0, 0, 0),
                            ofColor(255, 255, 255)));
    
    //Medama
    for (int i = 0; i < medama_max_num; i++) {
        Medama tmp = Medama();
        medamaArray.push_back(tmp);
    }
    
}

//--------------------------------------------------------------
void ofApp::update(){
    //Medama
//    for (int i = 0; i < medamaArray.size(); i++) {
//        medamaArray[i].update();
//    }
    for (int i = 0; i < medama_num; i++) {
        medamaArray[i].update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackground(cslider_1);
    
    //Medama
//    for (int i = 0; i < medamaArray.size(); i++) {
//        medamaArray[i].draw();
//    }
    for (int i = 0; i < medama_num; i++) {
        medamaArray[i].draw();
    }
    
    //GUI
    gui.draw();
    
    if(toggle_0 == true) {
        ofSetColor(cslider_0);
        ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2, fslider_0);
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
