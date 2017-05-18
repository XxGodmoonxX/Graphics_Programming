//
//  main.cpp
//  graphic_second_2
//
//  Created by 渡辺　基暉 on 2017/04/20.
//  Copyright (c) 2017年 渡辺　基暉. All rights reserved.
//

#include <iostream>
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#include <math.h> //三角関数が使えるようになる

//wakita_ver
//void display(void) {
//    glClear(GL_COLOR_BUFFER_BIT); //ウィンドウの初期化
//    glBegin(GL_TRIANGLES); //三角形の描画を宣言
//    glColor3f(1.0f, 0.0f, 0.0f); //赤の頂点を描画　intは整数,fは少数のこと,float
//    glVertex2f(0.0f, 0.5f); //赤の頂点の位置を指定
//    glColor3f(0.0f, 1.0f, 0.0f); //緑の頂点を描画
//    glVertex2f(-0.5f, -0.5f); //緑の頂点の位置を指定
//    glColor3f(0.0f, 0.0f, 1.0f); //青の頂点を描画
//    glVertex2f(0.5f, -0.5f); //青の頂点の位置を指定
//    glEnd();
//    glFlush();
//}
//
//int main(int argc, char * argv[]) {
//    glutInit(&argc, argv); //GLUTの初期化
//    glutInitWindowSize(300, 300); //ウィンドウの作成
//    glutInitDisplayMode(GLUT_RGBA);
//    glutCreateWindow("triangle");
//    glutDisplayFunc(display);
//    glClearColor(1.0, 1.0, 1.0, 0.0); //背景色の初期化　RGB、alpha, 今は白
//    glutMainLoop();
//    return 0;
//}


//motoki_ver
int polygon_num; //多角形の頂点の数を指定

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT); //ウィンドウの初期化
    glColor3f(0.0, 0.5, 1.0);
    
    glBegin(GL_POLYGON); //多角形の描画を宣言　真ん中が0
//    glVertex2f(-0.3f, 0.5f);
//    glVertex2f(0.3f, 0.5f);
//    glVertex2f(0.8f, -0.5f);
//    glVertex2f(0.0f, -0.8f);
//    glVertex2f(-0.8f, -0.5f);

    polygon_num = 20; //多角形を何角形にするか (polygon_num)角形
    for (int i = 0; i < polygon_num; i++) {
        glVertex2f(cos(2.0 * M_PI/polygon_num * i), sin(2.0 * M_PI/polygon_num * i));
//        glVertex2f(cos(2.0 * M_PI/5.0 * 1.0), sin(2.0 * M_PI/5.0 * 1.0));
//        glVertex2f(cos(2.0 * M_PI/5.0 * 2.0), sin(2.0 * M_PI/5.0 * 2.0));
//        glVertex2f(cos(2.0 * M_PI/5.0 * 3.0), sin(2.0 * M_PI/5.0 * 3.0));
//        glVertex2f(cos(2.0 * M_PI/5.0 * 4.0), sin(2.0 * M_PI/5.0 * 4.0));
    }
    
    glEnd();
    glFlush();
}

int main(int argc, char * argv[]) {
    glutInit(&argc, argv); //GLUTの初期化
    glutInitWindowSize(300, 300); //ウィンドウの作成
    glutInitDisplayMode(GLUT_RGBA);
    glutCreateWindow("polygon");
    glutDisplayFunc(display);
    glClearColor(1.0, 1.0, 1.0, 0.0); //背景色の初期化　RGB、alpha, 今は白
    glutMainLoop();
    return 0;
}