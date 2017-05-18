//
//  main.cpp
//  graphic_third_2
//
//  Created by 渡辺　基暉 on 2017/04/27.
//  Copyright (c) 2017年 渡辺　基暉. All rights reserved.
//

#include <iostream>
#include <OPENGL/OpenGl.h>
#include <GLUT/glut.h>

void display(void) {
    glClearColor(0.0, 0.0, 0.0, 1.0); //RGB,alpha
    glClear(GL_COLOR_BUFFER_BIT); //背景色で塗りつぶし
    glColor3f(1.0, 1.0, 1.0); //白で物体を描画
    //物体を描画する命令
//    glutWireTeapot(0.5);
    glColor3f(0, 0.5, 0.5);
    glutWireSphere(2, 100, 50);
    
    glColor3f(0.5, 0.5, 0);
    glutWireTeapot(0.5);
//    glutWireCube(200);
    
    glFlush();
}

void resize(int width, int height) {
    //Viewportの設定
    glViewport(0, 0, width, height);
    
    //投影と視野の設定
    glMatrixMode(GL_PROJECTION); //投影行列を操作するよ
    glLoadIdentity(); //行列の初期化
    gluPerspective(45.0, width/height, 0.1, 100);
    //視野角、比率、near, far
    
    //カメラの設定モデルをどう見るか　モデルビュー
    glMatrixMode(GL_MODELVIEW); //モデルビュー行列を操作するよ
    glLoadIdentity(); //モデルビュー行列を初期化
//    gluLookAt( -0.5, 2.1, 2.0,      0.0, 0.0, 0.0,      0.0, 1.0, 0.0);
    //         視点のカメラの位置        どこを見るか          アップベクトル
    gluLookAt(0, 0, 0, 1, 1, 1000, 1, 1, 1);
}

int main(int argc, char * argv[]) { //
    glutInit(&argc, argv); //GLUTの初期化
    glutInitWindowSize(600, 600); //ウィンドウの作成
    glutInitDisplayMode(GLUT_RGBA);
    glutCreateWindow("hello3D");
    glutDisplayFunc(display); //描画処理の関数名
    glutReshapeFunc(resize); //ウィンドウ処理の関数名
//    glClearColor(1.0, 1.0, 1.0, 0.0); //背景色の初期化　RGB、alpha, 今は白
    glutMainLoop();
    return 0;
}