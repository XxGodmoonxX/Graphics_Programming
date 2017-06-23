//
//  cube.hpp
//  20170622_HelloObject2
//
//  Created by 渡辺　基暉 on 2017/06/22.
//
//

#ifndef cube_hpp
#define cube_hpp

#include <stdio.h>
#include <iostream> //C++に必要
#include "ofMain.h" //oF使うため
//<> C++の機能 ""作ったものを追加(oFは誰かが作ったもの)

class Cube {
public:
    
    //member
    ofVec2f pos;
    //pos.x pos.yが使える
    ofColor color;
    float cube_size;
    float angle;
    
//    ofVec2f speed;
    
    //constructor
    Cube();
    
    //method
    void update();
    void draw();
};


#endif /* cube_hpp */
