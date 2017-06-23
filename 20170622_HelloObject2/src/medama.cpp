//
//  medama.cpp
//  20170622_HelloObject2
//
//  Created by 渡辺　基暉 on 2017/06/22.
//
// cppはその中身

#include "medama.hpp"

//constructor
//memberの初期設定
Medama::Medama() {
    pos = ofVec2f(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
    speed = ofVec2f(ofRandom(-2, 2), ofRandom(-2, 2));
    color = ofColor(ofRandom(255), ofRandom(255), ofRandom(255), 50);
    size = ofRandom(30, 50);
    size_white = ofRandom(20);
    size_black = ofRandom(10);
}

//更新処理(描画を伴わない)
void Medama::update() {
//    pos += speed;
    //add noise
    pos += speed + ofVec2f(ofRandom(-2, 2), ofRandom(-2, 2));
    
    //境界条件
    if (pos.x > ofGetWidth()) pos.x = 0; //right
    if (pos.x < 0) pos.x = ofGetWidth(); //left
    if (pos.y > ofGetHeight()) pos.y = 0; //bottom
    if (pos.y < 0) pos.y = ofGetHeight(); //top
}

//更新処理(描画を伴う)
void Medama::draw() {
    ofSetColor(color);
    ofDrawCircle(pos.x, pos.y, size);
    
    ofSetColor(255, 255, 255);
    ofDrawCircle(pos.x, pos.y, size_white);
    
    ofSetColor(0, 0, 0);
    ofDrawCircle(pos.x, pos.y, size_black);
}
