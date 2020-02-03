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

    //graphical debug screen
    ofxCenteredTrueTypeFont font;
    string digit [4];

    //declare codes
    int code [10];
    int codeLength;

    //unlock mechanics
    int unlock;
    int resetClock;

    //text messages
    string question [10];
    string message [10];
    string clue [10];
    int clueNum = 6;

    //audio messages
    ofSoundPlayer sound [10];


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
