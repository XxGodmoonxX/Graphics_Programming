#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "medama.hpp"

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
    
    //Medama
    vector<Medama> medamaArray;
    
    //GUI
    ofxPanel gui;
    ofxToggle toggle_0;
    ofxFloatSlider fslider_0;
    ofxColorSlider cslider_0;
    ofxColorSlider cslider_1;
    ofxIntSlider medama_num;
    
    int medama_max_num = 200;
		
};
