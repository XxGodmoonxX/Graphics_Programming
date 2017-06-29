#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    for (int i = 0; i < 100; i++) {
        Medama tmp = Medama(); //tmp = temporary 一時的なやつ
        medamaArray.push_back(tmp);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    
    for (int i = 0; i < medamaArray.size(); i++) {
        medamaArray[i].update();
    }
    
//    for (int i = 0; i < num; i++) {
//        medamas[i].update();
//    }
    
    cube.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    for (int i = 0; i < medamaArray.size(); i++) {
        medamaArray[i].draw();
    }
    
//    for (int i = 0; i < num; i++) {
//        medamas[i].draw();
//    }
    
    cube.draw();
    
    //フレームレートを表示
    ofSetColor(255, 255, 255);
    ofToString(ofGetFrameRate());
    ofDrawBitmapString(ofToString(ofGetFrameRate()), 20, 20);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if (key == 'n') {
        Medama tmp = Medama();
        medamaArray.push_back(tmp);
    }
    
    if (key == 'd') {
        if (medamaArray.size() > 0) {
            medamaArray.pop_back();
            std::cout << "pop_back is called" << "\n"; //プログラムが実行されてるか確認
        }
        
    }
    
    if (key == 'c') {
        medamaArray.clear();
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
