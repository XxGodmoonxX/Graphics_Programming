//
//  cube.cpp
//  20170622_HelloObject2
//
//  Created by 渡辺　基暉 on 2017/06/22.
//
//

#include "cube.hpp"

Cube::Cube() {
    pos = ofVec2f(ofGetWidth()/2, ofGetHeight()/2);
//    speed = ofVec2f(ofRandom(5, 10), ofRandom(5, 10));
    color = ofColor(255, 255, 255, 100);
    cube_size = 100;
    angle = 10;
}

//描画を伴わない更新処理
void Cube::update() {
//    pos += speed;
    angle += 10;
}

void Cube::draw() {
    ofPushMatrix();
    ofTranslate(pos.x, pos.y);
    ofRotateZ(angle);
    ofSetColor(color);
    ofDrawRectangle(-cube_size/2, -cube_size/2, cube_size, cube_size);
    ofPopMatrix();
}
