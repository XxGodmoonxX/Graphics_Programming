#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofBackground(200, 200, 200);
    
    ofEnableLighting();
    ofEnableDepthTest();
    ofSetSmoothLighting(true);
    
    //GUI setting
    gui.setup();
    gui.add(toggle_0.setup("show", true));
    gui.add(cSlider_0.setup("backgroudColor",
                            ofColor(255, 255, 255),
                            ofColor(0, 0, 0),
                            ofColor(255, 255, 255)));
    gui.add(cSlider_1.setup("boxColor",
                            ofFloatColor(0.0, 0.0, 0.0),
                            ofFloatColor(0.0, 0.0, 0.0),
                            ofFloatColor(1.0, 1.0, 1.0)));
    
    //light setting
    light.setup();
    ofFloatColor ambient = ofFloatColor(0.2, 0.8, 0.8); //環境光
    ofFloatColor diffuse = ofFloatColor(0.4, 0.4, 0); //物体が跳ね返す色
    ofFloatColor specular = ofFloatColor(1.0, 1.0, 1.0);
    light.setAmbientColor(ambient);
    light.setDiffuseColor(diffuse);
    light.setSpecularColor(specular);
//    light.setDirectional();
//    light.setPointLight();
    light.setSpotlight();
//    light.setPosition(300, 300, 300);
    light.enable();
    
    //material setting
    ofFloatColor ambientMat = ofFloatColor(0.4, 0.8, 0.8);
    ofFloatColor diffuseMat = ofFloatColor(0.0, 0.4, 0.9);
    ofFloatColor specularMat = ofFloatColor(0.0, 0.8, 0.8);
    material.setAmbientColor(ambientMat);
    material.setDiffuseColor(diffuseMat);
    material.setSpecularColor(specularMat);
//    material.setShininess(0.5);
    
    //camera setting
    camera.setDistance(400);
    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackground(cSlider_0);
    
    //3D ライトや奥行き有効
    light.draw();
    
    ofEnableLighting();
    ofEnableDepthTest();
    //camera
    camera.begin();
        material.begin();
            if(toggle_0 == true) {
                ofSetColor(cSlider_1);
                box.draw();
            }
        material.end();
    camera.end();
    ofDisableLighting();
    ofDisableDepthTest();
    
    //2D
    //gui
    gui.draw(); //2次元で描画したいから、上記の3次元描写とわける
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
