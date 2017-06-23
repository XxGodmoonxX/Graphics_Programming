//
//  medama.hpp
//  20170622_HelloObject2
//
//  Created by 渡辺　基暉 on 2017/06/22.
//
// hppは一覧

#ifndef medama_hpp
#define medama_hpp

#include <stdio.h>
#include <iostream> //C++に必要
#include "ofMain.h" //oF使うため
    //<> C++の機能 ""作ったものを追加(oFは誰かが作ったもの)

class Medama {
public:
    
    //member
    ofVec2f pos;
    //pos.x pos.yが使える
    ofColor color;
    float size;
    float size_white; //白目
    float size_black; //黒目
    
    ofVec2f speed;
    
    //constructor
    Medama();
    
    //method
    void update();
    void draw();
};

#endif /* medama_hpp */
