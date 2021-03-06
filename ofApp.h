#pragma once

#include "ofMain.h"
#include "ofxCenteredTrueTypeFont.h"
#include "ofUtils.h"
#include "ofxThermalPrinter.h"

class ofApp : public ofBaseApp{

public:
    void setup();
    void update();
    void draw();
    void exit();

    void keyPressed(int key);

    //hdmi output
    ofxCenteredTrueTypeFont font;
    string digit [4];
    ofImage breaker;
    ofImage enigma;
    float enigmaScale;
    float breakerScale;

    //declare codes
    int code [10];
    int codeLength;

    //unlock mechanics
    int unlock;
    int resetClock;

    //text messages
    ofBuffer message [10][3];
    string question [10];
    string clue [10];
    int clueNum = 10;
    string overflow[10];

    //audio messages
    ofSoundPlayer sound [10][3];

    //keypad input
    int keyCount;
    int pad [4];
    int solve;

    //serial
    ofSerial mySerial;
    char myByte = NULL;
    
    //slideshow display
    int slide = 0;
    
    //speakers

    //printer    
    ofxThermalPrinter printer;
};
