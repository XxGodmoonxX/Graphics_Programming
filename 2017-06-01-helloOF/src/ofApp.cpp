#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60); //人間は1秒60回更新されると没入感
    ofBackground(200, 200, 200);
    ofSetBackgroundAuto(false); //oFは勝手にswap buffer 画面初期化される

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(0, 128, 255, 40);
    ofDrawRectangle(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()), 100, 100);
    
    ofSetColor(0, 0, 0);
    ofDrawBitmapString("hello", 20, 20); //char 文字 string n文字
    
//    ofGetFrameRate(); //float 数字 型が違う、stringではない
//    ofToString(); string化
//    ofDrawBitmapString(ofToString(ofGetFrameRate()), 20, 50);
    //ofSetBackgroundAuto(false); とは共存できない、毎回数字が上からかかれて潰れていく

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 'f') {
        ofToggleFullscreen();
    }
    
    if(key == 'q') {
        ofSetBackgroundAuto(true);
    }

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    ofNoFill();
    ofCircle(x, y, 10);

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    ofFill();
    ofSetColor(0, 100, 255);
    ofCircle(x, y, 10);

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    ofSetBackgroundAuto(false);
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
