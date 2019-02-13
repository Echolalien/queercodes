#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    //give codes
    codeLength = 4;
    code[0] = 1989;
    code[1] = 1234;
    code[2] = 0000;
    code[3] = 6969;
    code[4] = 0420;
    code[5] = 1337;

    //give messages
    message[0] = "lorem ipsum salat dolor ipsos";
    message[1] = "when i was a young boy my father took me into the city";
    message[2] = "in west philadelphia born n raised";
    message[3] = "the sun said it hurts to become";

    //audio samples
    //sound[0].load("music1.wav");
    //sound[1].load("music2.wav");

    //firmata

    //LCD
    
    //speakers

    //printer
    printer.open("/dev/tty.PL2303-00002014");

    //graphical debug screen
    ofSetBackgroundColor(0);
    font.load("arial", 20, true, true, false);
    ofSetColor(255);
}

//--------------------------------------------------------------
void ofApp::update(){
    for(int i = 0; i<4; i++){
        if(i<keyCount){
            digit[i] = "*";
        }
        else{
            digit[i] = "_";
        }
    }

    if(keyCount==codeLength && resetClock==0){
        int solve = (pad[0]*1000)+(pad[1]*100)+(pad[2]*10)+pad[3];
        for(int i = 0; i<6; i++){
            if(solve==code[i]){
                unlock=i+1;
                if(sound[i].isLoaded()==true){
                    sound[i].play();
                }
            }
            else if (sound[i].isPlaying()==true){
                sound[i].stop();
            }
        }
        resetClock++;
    }
    else if(resetClock>0){
        if(resetClock<700){
            resetClock++;
        }
        else{
            resetClock=0;
            keyCount=0;
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    font.drawString("Enter code:", 20, 50);
    for(int i = 0; i<codeLength; i++){
        font.drawString(digit[i], 20+i*20, 100);
    }
    if(unlock>0){
        font.drawString(message[unlock-1], 20, 150);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    cout << key << endl;
    for(int i = 0; i<10; i++){
        if(key==i+48 && keyCount<codeLength){
            pad[keyCount]=i;
            keyCount++;
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}
