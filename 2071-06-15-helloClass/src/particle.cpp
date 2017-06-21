//
//  particle.cpp
//  2071-06-15-helloClass
//
//  Created by 渡辺　基暉 on 2017/06/15.
//
//

#include "particle.hpp"

//constructor
Particle::Particle() { //memberに対して値を設定
    //initialization 初期化
    xPos = ofRandom(ofGetWidth());
    yPos = ofRandom(ofGetHeight());
    
    xSpeed = ofRandom(-3, 3);
    ySpeed = ofRandom(-3, 3);
    
    radius = ofRandom(10);
    
    color = ofColor(ofRandom(255), ofRandom(255), ofRandom(255), ofRandom(150, 220));
}

void Particle::update() {
    xPos += xSpeed;
    yPos += ySpeed;
    
    color = ofColor(ofRandom(255), ofRandom(255), ofRandom(255), ofRandom(150, 220));
    
    //右端もしくは左端に到着したら（画面から飛び出たら）
    
    //右端
    if (xPos > ofGetWidth()) {
        xPos = 0;
    }
    //左端
    if (xPos < 0) {
        xPos = ofGetWidth();
    }
    //下端
    if (yPos > ofGetHeight()) {
        yPos = 0;
    }
    //上端
    if (yPos < 0) {
        yPos = ofGetHeight();
    }
}

void Particle::draw() {
    ofSetColor(color);
    ofDrawCircle(xPos, yPos, radius);
}
