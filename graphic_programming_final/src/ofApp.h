#pragma once

#include "ofMain.h"
#include "midi.hpp"
#include "ofxGui.h"
#include "particle.hpp"

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
    
    float positionX;
    
    float pmouseX;
    float pmouseY;
    
    Particle particles[500];
    
    Midi midi;
    
    ofxPanel gui;
    ofxSlider<int> knob[8];
    ofxSlider<int> slider[8];
		
};
