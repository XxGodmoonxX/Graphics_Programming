#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
    float xn, yn, zn;
    float x, y, z; //xn, yn, znを一時的に保存する変数
    
    ofxPanel gui;
    ofxIntSlider num;
    ofxFloatSlider a, b, c, d, scale;
    
    ofVbo vbo; //頂点周りの情報
    vector<ofVec3f> points; //頂点の配列,geometry
    vector<ofIndexType> indices; //接続情報、この線はどの頂点を接続してるtoporogy
    
    ofEasyCam cam;
    float rotate_x;
    float rotate_y;
    
};
