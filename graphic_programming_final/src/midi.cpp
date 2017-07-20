//
//  midi.cpp
//  graphic_programming_final
//
//  Created by 渡辺　基暉 on 2017/07/16.
//
//

#include "midi.hpp"

Midi::Midi() {
    
}

void Midi::setup() {
    
    //
    midiIn.listPorts();
    midiOut.listPorts();
    
    midiIn.openPort(0);
    midiOut.openPort(0);
    
    midiIn.ignoreTypes(false, false, false);
    
    midiIn.addListener(this);
    
    midiIn.setVerbose(true);
    
    channel = 1;
    note = 0;
    velocity = 0;
    
    i = 0;
    
    for (int i = 0; i < 8; i++) {
        buttonSolo[i] = false;
        buttonMute[i] = false;
        buttonRec[i] = false;
    }
    
}

void Midi::update() {
    
    NoteOnOff = ofxMidiMessage::getStatusString(midiMessage.status);
    
    
    for (int i = 0; i < 8; i++) {
        
        //スライダー
        if (midiMessage.control == i) {
        sliders[i] = midiMessage.value;
        }
        
        //ノブ
        if (midiMessage.control == i + 16) {
            knobs[i] = midiMessage.value;
        }
        
        //右側のボタン
        //ソロボタン
        if (midiMessage.control == i + 32 && midiMessage.value == 127) {
            buttonSolo[i] = true;
        } else if (midiMessage.control == i + 32 && midiMessage.value == 0) {
            buttonSolo[0] = false;
        }
        
        //ミュートボタン
        if (midiMessage.control == i + 48 && midiMessage.value == 127) {
            buttonMute[i] = true;
        } else if (midiMessage.control == i + 48 && midiMessage.value == 0) {
            buttonMute[i] = false;
        }
        
        //レコードボタン
        if (midiMessage.control == i + 64 && midiMessage.value == 127) {
            buttonRec[i] = true;
        } else if (midiMessage.control == i + 64 && midiMessage.value == 0) {
            buttonRec[i] = false;
        }
    }
    
    //左側のボタン
    if (midiMessage.control == 58 && midiMessage.value == 127) {
        buttonTrackLeft = true;
    } else if (midiMessage.control == 58 && midiMessage.value == 0) {
        buttonTrackLeft = false;
    }
    if (midiMessage.control == 59 && midiMessage.value == 127) {
        buttonTrackRight = true;
    } else if (midiMessage.control == 59 && midiMessage.value == 0) {
        buttonTrackRight = false;
    }
    if (midiMessage.control == 46 && midiMessage.value == 127) {
        buttonCycle = true;
    } else if (midiMessage.control == 46 && midiMessage.value == 0) {
        buttonCycle = false;
    }
    if (midiMessage.control == 60 && midiMessage.value == 127) {
        buttonMarkerSet = true;
    } else if (midiMessage.control == 60 && midiMessage.value == 0) {
        buttonMarkerSet = false;
    }
    if (midiMessage.control == 61 && midiMessage.value == 127) {
        buttonMarkerLeft = true;
    } else if (midiMessage.control == 61 && midiMessage.value == 0) {
        buttonMarkerLeft = false;
    }
    if (midiMessage.control == 62 && midiMessage.value == 127) {
        buttonMarkerRight = true;
    } else if (midiMessage.control == 62 && midiMessage.value == 0) {
        buttonMarkerRight = false;
    }
    if (midiMessage.control == 43 && midiMessage.value == 127) {
        buttonRewind = true;
    } else if (midiMessage.control == 43 && midiMessage.value == 0) {
        buttonRewind = false;
    }
    if (midiMessage.control == 44 && midiMessage.value == 127) {
        buttonFastForward = true;
    } else if (midiMessage.control == 44 && midiMessage.value == 0) {
        buttonFastForward = false;
    }
    if (midiMessage.control == 42 && midiMessage.value == 127) {
        buttonStop = true;
    } else if (midiMessage.control == 42 && midiMessage.value == 0) {
        buttonStop = false;
    }
    if (midiMessage.control == 41 && midiMessage.value == 127) {
        buttonPlay = true;
    } else if (midiMessage.control == 41 && midiMessage.value == 0) {
        buttonPlay = false;
    }
    if (midiMessage.control == 45 && midiMessage.value == 127) {
        buttonRecord = true;
    } else if (midiMessage.control == 45 && midiMessage.value == 0) {
        buttonRecord = false;
    }
    
}

void Midi::draw() {

    ofSetColor(155,0,0);
    
    ofNoFill();
    ofRect(0,30,ofGetWidth(),70);
    ofRect(0,110,ofGetWidth(),ofGetHeight()-120);
    
    ofSetColor(0);
    ofDrawBitmapString("KORG NANO KONTROL 2 ", 40,20);
    
    //Track
    ofDrawBitmapString("trackLeft = " + ofToString(buttonTrackLeft), 40,50);
    ofDrawBitmapString("trackRight = " + ofToString(buttonTrackRight), 170,50);
    
    //Maker
    ofDrawBitmapString("cycle = " + ofToString(buttonCycle), 40,70);
    ofDrawBitmapString("markerSet = " + ofToString(buttonMarkerSet), 310,70);
    ofDrawBitmapString("markerLeft = " + ofToString(buttonMarkerLeft), 450,70);
    ofDrawBitmapString("markerRight = " + ofToString(buttonMarkerRight), 590,70);
    
    //Transport
    ofDrawBitmapString("Rewind = " + ofToString(buttonRewind), 40,90);
    ofDrawBitmapString("FastForward = " + ofToString(buttonFastForward), 170,90);
    ofDrawBitmapString("Stop = " + ofToString(buttonStop), 310,90);
    ofDrawBitmapString("Play = " + ofToString(buttonPlay), 450,90);
    ofDrawBitmapString("Record = " + ofToString(buttonRecord), 590,90);
    
    
    for (int i = 0; i < 8; i++) {
        //Sliders
        ofDrawBitmapString("slider[i+1] = " + ofToString(sliders[i]), 40, 130 + 20*(i-1));
        
        //knobs
        ofDrawBitmapString("knobs[i+1] = " + ofToString(knobs[i]), 180, 130 + 20*(i-1));
        
        //Solo Buttons
        ofDrawBitmapString("SoloButton[i+1] = " + ofToString(buttonSolo[i]), 320, 130 + 20*(i-1));
        
        //Mute Buttons
        ofDrawBitmapString("MuteButton[i+1] = " + ofToString(buttonMute[i]), 460, 130 + 20*(i-1));
        
        //Record Buttons
        ofDrawBitmapString("RecButton[I+1] = " + ofToString(buttonRec[i]), 600, 130 + 20*(i-1));
    }
}

void Midi::exit() {
    
    // clean up
    midiIn.closePort();
    midiIn.removeListener(this);
}

void Midi::newMidiMessage(ofxMidiMessage& msg) {
    
    // make a copy of the latest message
    midiMessage = msg;
}
