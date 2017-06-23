#pragma once

#include "ofMain.h"
#include "medama.hpp" //ここに追加
#include "cube.hpp"

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
		
    //ここに追加
    static const int num = 100;
    //const 定数 staticはつけると思っとけ
    //この100はこれによって変えられなくなる
    Medama medamas[num];
    
    Cube cube;
    
};
