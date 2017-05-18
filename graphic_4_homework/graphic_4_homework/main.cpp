//
//  main.cpp
//  graphic_4_homework
//
//  Created by 渡辺　基暉 on 2017/05/11.
//  Copyright (c) 2017年 渡辺　基暉. All rights reserved.
//

#include <iostream>
#include <OPENGL/OpenGl.h>
#include <GLUT/glut.h>

//大域変数を使うときはincludeの下

const float lightPosition[4] = {5.25, 2.0, 0.25, 1.0}; // {x, y, z, }
const float teapotAmbient[4] = {1.0, 1.0, 1.0, 1.0}; //環境光
const float teapotDiffuse[4] = {0.0, 0.5, 1.0, 1.0}; //拡散反射光
const float teapotSpecular[4] = {1.0, 1.0, 1.0, 1.0}; //ハイライト
const float teapotShininess[1] = {20.0}; //ハイライトの大きさ

//const float lightPosition2[4] = {-5.25, 2.0, 0.25, 1.0}; // {x, y, z, }
//const float teapotAmbient2[4] = {1.0, 1.0, 1.0, 1.0}; //環境光
//const float teapotDiffuse2[4] = {0.3, 0.5, 0.3, 1.0}; //拡散反射光
//const float teapotSpecular2[4] = {1.0, 1.0, 1.0, 1.0}; //ハイライト
//const float teapotShininess2[1] = {20.0}; //ハイライトの大きさ

void display() {
    glClearColor(0.0, 0.0, 0.0, 1.0); //加法混色、全部0が黒、1が白
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // | = それに加えて
    //    glColor3f(1.0, 1.0, 1.0); //float
//    glutSolidTeapot(0.5);
    glutWireTeapot(0.5);
    
//    glutSolidSphere(5.0, 2.0, 1.0);
    
    glFlush();
}

void resize(int width, int height) { //resizeは引数2つ必要
//    glViewport(0, 0, width, height); //左下の座標の幅、高さ
//    
//    //PROJECTION
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    gluPerspective(45.0, width/height, 0.1, 100.0);
//    
//    //MODELVIEW
//    glMatrixMode(GL_MODELVIEW);
//    glLoadIdentity();
//    gluLookAt(-0.5, 2.4, 1.2, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0); //アップベクトル　yが1だと上を向く
//    gluLookAt(-0.5, 2.4, 1.2, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    
    for (float i = -3; i < 3; i += 0.001) {
        glViewport(0, 0, width, height);
        
        //PROJECTION
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluPerspective(45.0, width/height, 0.1, 100.0);
        
        //MODELVIEW
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        gluLookAt(-0.5, i, i, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
        
        if(i == 2.999) {
            i = -3;
        }
        
    }
    
}

void setup() {
    //light setting
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING); //光源は8つ設置可能
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
    
    //material setting
    glMaterialfv(GL_FRONT, GL_AMBIENT, teapotAmbient); //前側のみ裏側の描画はしない表面の環境光を設定、値はAmbientに入ってるよ
    glMaterialfv(GL_FRONT, GL_DIFFUSE, teapotDiffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, teapotSpecular);
    glMaterialfv(GL_FRONT, GL_SHININESS, teapotShininess);
    
//    //light setting 2
//    glEnable(GL_DEPTH_TEST);
//    glEnable(GL_LIGHTING); //光源は8つ設置可能
//    glEnable(GL_LIGHT1);
//    glLightfv(GL_LIGHT1, GL_POSITION, lightPosition2);
//    
//    //material setting 2
//    glMaterialfv(GL_FRONT, GL_AMBIENT, teapotAmbient2);
//    glMaterialfv(GL_FRONT, GL_DIFFUSE, teapotDiffuse2);
//    glMaterialfv(GL_FRONT, GL_SPECULAR, teapotSpecular2);
//    glMaterialfv(GL_FRONT, GL_SHININESS, teapotShininess2);
}

int main(int argc, char * argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(600, 600);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH);
    glutCreateWindow("Hello Rendaring");
    glutDisplayFunc(display);
    glutReshapeFunc(resize);
    
    setup();
    
    glutMainLoop();
    
    return 0;
}