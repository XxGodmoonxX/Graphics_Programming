//
//  midi.hpp
//  graphic_programming_final
//
//  Created by 渡辺　基暉 on 2017/07/16.
//
//
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

#ifndef midi_hpp
#define midi_hpp

#include <stdio.h>
#include <iostream>
#include "ofMain.h" //oF使うため
#include "ofxMidi.h" //midi関連使うため

class Midi : public ofxMidiListener {
public:
    
    //メンバー
    stringstream text;
    string NoteOnOff;
    
    ofxMidiIn midiIn;
    ofxMidiMessage midiMessage;
    
    ofxMidiOut midiOut;
    int channel, note, velocity;
    
    //Midi Fighter Variables
    int mfSlider1, mfSlider2;
    int mfknob1, mfknob2;
    bool mfButton[16];
    bool mfToggle[4];
    
    //ノブの数
    int knobs[8];
    
    //スライダーの数
    int sliders[8];
    
    //各ボタンの数
    //右側
    bool buttonSolo[8];
    bool buttonMute[8];
    bool buttonRec[8];
    //左側
    bool buttonTrackLeft, buttonTrackRight;
    bool buttonCycle;
    bool buttonMarkerSet, buttonMarkerLeft, buttonMarkerRight;
    bool buttonRewind, buttonFastForward;
    bool buttonStop, buttonPlay, buttonRecord;
    
    int i;
    
    //コンストラクター
    Midi();
    
    //メソッド
    void setup();
    void update();
    void draw();
    void exit();
    void newMidiMessage(ofxMidiMessage& eventArgs);
    

};

#endif /* midi_hpp */
