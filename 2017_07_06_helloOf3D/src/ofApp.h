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
    
    //3次元
    vector<ofVec3f> position;
    vector<ofVec3f> velocity;
    
    ofEasyCam camera; //簡単にカメラが使える
    
    //光源
    ofLight light;
    ofMaterial material;
    
    ofBoxPrimitive box; //中に光線ベクトル
    
    //GUI
    ofxPanel gui;
    ofxToggle toggle_0;
    ofxColorSlider cSlider_0;
    ofxColorSlider cSlider_1;
};
