#pragma once

#pragma GCC diagnostic ignored "-Wdeprecated-declarations" //黄色い注意がでてこなくなる、注意のレベルを下げる

#include "ofMain.h"

class ofApp : public ofBaseApp{ //ofApp.h は概要

	public:
		void setup(); //初期化
		void update(); //frameごとに呼ばれる、描画を伴わない処理
		void draw(); //frameごとに呼ばれる、描画を伴う処理

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
		
};
