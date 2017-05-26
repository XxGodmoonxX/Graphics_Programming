//
//  main.cpp
//  graphic_6_1
//
//  Created by 渡辺　基暉 on 2017/05/25.
//  Copyright © 2017年 渡辺　基暉. All rights reserved.
//

#pragma GCC diagnostic ignored "-Wdeprecated-declarations" //黄色い注意がでてこなくなる、注意のレベルを下げる

#include <iostream>
#include <OPENGL/OpenGl.h>
#include <GLUT/glut.h>

//大域変数を使うときはincludeの下

//setup()
const float lightPosition[4] = {5.25, 2.0, 0.25, 1.0}; // {x, y, z, }
const float teapotAmbient[4] = {1.0, 1.0, 1.0, 1.0}; //環境光
const float teapotDiffuse[4] = {1.0, 1.0, 0.3, 1.0}; //拡散反射光
const float teapotSpecular[4] = {1.0, 1.0, 1.0, 1.0}; //ハイライト
const float teapotShininess[1] = {20.0}; //ハイライトの大きさ

//idle()
float rotation = 0.0;

float rotation_sun = 0.0;
float rotation_mercury = 0.0;
float rotation_venus = 0.0;
float rotation_earth = 0.0;

//key()
bool bFullscreen = true; //bool型　true =　真, false = 偽しかとらない
bool light_position = true;

void display() {
    glClearColor(0.0, 0.0, 0.0, 1.0); //加法混色、全部0が黒、1が白
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // | = それに加えて
    //    glColor3f(1.0, 1.0, 1.0); //float
    //    glutSolidTeapot(0.5);
    
    //Affine Transformation
    //対象物だけにかかってほしい、2つ目のティーポット。行列変換は反対から読む
//        glPushMatrix();
//    
//            glRotatef(-30, 1.0, 0.0, 0.0);
//            glTranslatef(1.0, 0.0, -1.2);
//            glScalef(0.5, 0.5, 0.5);
//            glutSolidTeapot(0.5);
//            //Teapot → Scale → Translate → Rotate
//    
//        glPopMatrix();
//    
//        glPushMatrix();
//    
//        for(int i = 0; i < 360; i += 10) {
//            glRotatef(i, 1.0, 0.0, 0.0);
//            glutSolidTeapot(0.5);
//        }
//    
//        glPopMatrix();
    
//    glPushMatrix();
//        glRotatef(rotation, 0.0, 1.0, 0.0);
//        glutSolidTeapot(0.5);
//    glPopMatrix();
    
//    glPushMatrix();
//    
//    glRotatef(rotation_earth, 0.0, 1.0, 0.0); //地球
//    glTranslatef(1.0, 0.0, 0.0); //xに
//    glutSolidSphere(0.15, 20, 20); //
//    
//    glPopMatrix();
//    
//    glPushMatrix();
//    glRotatef(rotation_venus, 0.0, 1.0, 0.0); //金星
//    glTranslatef(0.7, 0.0, 0.0); //xに
//    glutSolidSphere(0.1, 20, 20); //
//    glPopMatrix();
//    
//    glPushMatrix();
//    
//    glRotatef(rotation_sun, 0.0, 1.0, 0.0); //太陽
//    glutSolidSphere(0.2, 20, 20); //center
//    
//    glTranslatef(0.3, 0.0, 0.0); //xに0.3
//    glRotatef(rotation_mercury, 0.0, 1.0, 0.0); //水星
//    glutSolidSphere(0.05, 20, 20); //
//    
//    glPopMatrix();
//    
//    //    glFlush(); //シングルバッファはこれ
//    glutSwapBuffers();
    
    float i_x, i_y, i_z;
    
    for(i_x = 0; i_x < 5; i_x += 1) {
        for(i_y = 0; i_y < 5; i_y += 1) {
            for(i_z = 0; i_z < 5; i_z += 1) {
                glPushMatrix();
                    //material setting
                    const float cubeDiffuse[4] = {i_x/5, i_y/5, i_z/5, 1.0}; //拡散反射光
                    glMaterialfv(GL_FRONT, GL_DIFFUSE, cubeDiffuse);
                
                    //5 * 5 * 5 のキューブ
                    glRotatef(rotation, 0.0, 1.0, 0.0);
                    glTranslatef(i_x-2, i_y-2, i_z-2);
                    glutSolidCube(0.3);
                
                    glRotatef(rotation, 0.0, 1.0, 0.0);
                    glTranslatef(i_x-2.5, i_y-2.5, i_z-2.5);
                    glutWireCube(0.3);
                glPopMatrix();
            }
        }
    }
    
    glutSwapBuffers();
}

void resize(int width, int height) { //resizeは引数2つ必要
    glViewport(0, 0, width, height); //左下の座標の幅、高さ
    
    //PROJECTION
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, width/height, 0.1, 100.0);
    
    //MODELVIEW
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
//    gluLookAt(-0.5, 2.4, 1.2, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0); //アップベクトル　yが1だと上を向く
    gluLookAt(0.0, 2.0, 6.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0); //最初の3つが自分のカメラ座標
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
}

void idle() {
    rotation += 1.0;
    
//    rotation_sun += 1.0;
//    //描画を強制的に送る
//    
//    rotation_mercury += 0.241;
//    
//    rotation_venus += 0.615;
//    
//    rotation_earth += 1.0;
    
    glutPostRedisplay();
}

void mouse(int button, int state, int x, int y) { //4つ引数必要 マウス関連の関数は引数4つとGLUTで決まっている
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) { //マウスの左ボタンが押されたなら
        exit(0); //プログラムを終了する exit myself
    }
    if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
        rotation += 30;
        glutReshapeWindow(800, 800);
    }
}

void key(unsigned char key, int x, int y) { //char charactor 文字を扱う型
    //switch文
    switch (key) { //switch(評価対象)
        case 'f': //case ~~ fの文字が打たれたら if = case,else if = case,else = default　って感じ
            //if(bFullscreen == true) {
            if(bFullscreen) { //このように省略可能
                glutReshapeWindow(600, 600);
            } else if (!bFullscreen) { //!は反転　!bFullscreenと反対、trueならfalse
                glutFullScreen();
            }
            bFullscreen = !bFullscreen;
            break; //最後break
            
        case 'r':
            if(light_position) {
                float lightPosition[4] = {-5.25, 2.0, 0.25, 1.0};
                glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
            } else if (!light_position) {
                float lightPosition[4] = {5.25, 2.0, 0.25, 1.0};
                glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
            }
            light_position = !light_position;
            break;
            
        default: //どれでもない場合
            break;
    }
}

int main(int argc, char * argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(600, 600);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
    glutCreateWindow("mouse & key");
    glutDisplayFunc(display);
    glutReshapeFunc(resize);
    
    setup();
    
    glutIdleFunc(idle); //アニメーション
    glutMouseFunc(mouse); //マウスの入力
    glutKeyboardFunc(key); //キーボードの入力
    
    glutMainLoop();
    
    return 0;
}
