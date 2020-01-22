#pragma once

#include "ofMain.h"
//#include "ofxThermalPrinter.h"

class ofApp : public ofBaseApp{

public:
    void setup();
    void update();
    void draw();
    void exit();

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

    //graphical debug screen
    ofTrueTypeFont font;
    string digit [4];

    //declare codes
    int code [6];
    int codeLength;

    //unlock mechanics
    int unlock;
    int resetClock;

    //text messages
    string message [5];

    //audio messages
    ofSoundPlayer sound [6];


    //keypad input
    int keyCount;
    int pad [4];

    //serial
    ofSerial mySerial;
    int myByte = 0;
    
    //speakers

    //printer    
    //ofxThermalPrinter printer;
};
