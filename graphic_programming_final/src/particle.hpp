//
//  particle.hpp
//  2071-06-15-helloClass
//
//  Created by 渡辺　基暉 on 2017/06/15.
//
//

#ifndef particle_hpp
#define particle_hpp

#include <stdio.h> //C言語のやつ
#include <iostream>
#include "ofMain.h" //oF関係の使うよ

class Particle {
    
    //なにもしないとprivate
public:
    
    //member
    float xPos;
    float yPos;
    float xSpeed;
    float ySpeed;
    float radius; //radius of particle
    
    ofColor color; //#include "ofMain.h"が必要
    
    //constructor
    Particle(); //自分のクラス名,voidって書くな
    
    //method
    void update();
    void draw();
    
};

#endif /* particle_hpp */
