#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    cam.setDistance(500);
    ofBackground(0, 0, 0);
    
    gui.setup();
    gui.add(a.setup("a", 1.4, -5.0, 5.0));
    gui.add(a.setup("b", 1.6, -5.0, 5.0));
    gui.add(a.setup("c", 1.0, -5.0, 5.0));
    gui.add(a.setup("d", 1.7, -5.0, 5.0));
    gui.add(num.setup("amount", 30000, 1000, 100000));
    gui.add(scale.setup("scale", 100, 1, 1000));
    
    //初期値
    x = 1;
    y = 1;
    z = 1;
    
    rotate_x = 0;
    rotate_y = 0;
}

//--------------------------------------------------------------
void ofApp::update(){
    points.clear();
    indices.clear();
    
    for (int i = 0; i < num; i++) {
        xn = sin(a * y) + c * cos(a * x);
        yn = sin(b * x) + c * cos(b * y);
        zn = cos(x);
        
        x = xn;
        y = yn;
        z = zn;
        
        points.push_back(scale * ofVec3f(xn, yn, zn));
        indices.push_back(i);
    }
    
    vbo.setVertexData(&points[0], points.size(), GL_STATIC_DRAW);
    vbo.setIndexData(&indices[0], indices.size(), GL_STATIC_DRAW);
    //GL_STATIC_DRAW 値が変化しない,&は参照
    rotate_x += 0.3;
    rotate_y += 0.3;
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    cam.begin();
    
    ofRotateX(rotate_x);
    ofRotateY(rotate_y);
    ofSetColor(255);
    vbo.drawElements(GL_POINTS, points.size());
    
    cam.end();
    
    //guiをカメラに影響させないためにendの後
    gui.draw();
    ofSetWindowTitle(ofToString(ofGetFrameRate()));
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if(key == 'r') { //パラメータリセット
        a = 1.4;
        b = 1.6;
        c = 1.0;
        d = 1.7;
    } else if (key == 'f') {
        ofToggleFullscreen(); //フルスクリーンをトグル
    } else if (key == 's') {
        ofSaveFrame(); //sキーで実行画面を保存
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
