#pragma once

#include "ofMain.h"
#include "particle.hpp" //ここに追加

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
		
    //大域変数ここに書く
    float positionX;
    
    float pmouseX;
    float pmouseY;
    
//    Particle p0, p1, p2;
    Particle particles[500];
};
