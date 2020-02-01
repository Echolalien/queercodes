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

    //give transcripts to output to printer
    message[0] = "lorem ipsum salat dolor ipsos";
    message[1] = "when i was a young boy my father took me into the city";
    message[2] = "in west philadelphia born n raised";
    message[3] = "the sun said it hurts to become";
    message[4] = "more filler";
    message[5] = "do you love the colour of the sky";
    
    //give clues
    clue[0] = "berlin wall";
    clue[1] = "first 4 numbers";
    clue[2] = "0x0 in binary";
    clue[3] = "nicenice";
    clue[4] = "blaze it";
    clue[5] = "n00b or pro";
    
    //give questions
    question[0] = "when did it fall";
    question[1] = "what are the";
    question[2] = "what is";
    question[3] = "lolol imagine";
    question[4] = "well,";
    question[5] = "elite eh";

    //audio samples
//    sound[0].load("code1.wav");
//    sound[1].load("code2.wav");
//    sound[2].load("code3.wav");
//    sound[3].load("code4.wav");

    //serial
    mySerial.setup("/dev/ttyACM0", 9600);

    //LCD
    
    //speakers

    //printer
    printer.open("/dev/serial0");
    printer.println("\n\nPrinter initialised");

    //graphical debug screen
    ofSetBackgroundColor(0);
    font.load("arial", 20, true, true, false);
    ofSetColor(255);
}

//--------------------------------------------------------------
void ofApp::update(){
    
    //serial inputs
    myByte = mySerial.readByte();
    if ( myByte == OF_SERIAL_NO_DATA ){
        //comment this out if you want your code to be legible
        //printf("no data was read\n");
    }
    else if ( myByte == OF_SERIAL_ERROR ){
//        printf("an error occurred\n");
    }
    else if ( myByte >= 48 && myByte < 58 && keyCount<codeLength){
        //cout << myByte-48 << endl;
        pad[keyCount]=myByte-48;
        keyCount++;
    }
    else if ( myByte == 110){
        if(slide < clueNum-1){
            slide++;
        }
        else{
            slide = 0;
        }
    }
    //digits to print
    for(int i = 0; i<4; i++){
        if(i<keyCount){
            digit[i] = "*";
        }
        else{
            digit[i] = "_";
        }
    }

//    //solve check
//    if(keyCount==codeLength && resetClock==0){
//        int solve = (pad[0]*1000)+(pad[1]*100)+(pad[2]*10)+pad[3];
//        for(int i = 0; i<6; i++){ //there'll be a memory leak here if u add codes but don't update that number of iterations lol
//            if(solve==code[i]){
//                unlock=i+1;
//                cout << "printing: " + message[i]<< endl;
//                printer.println(message[i]);
//                if(sound[i].isLoaded()==true){
//                    sound[i].play();
//                }
//            }
//
//            else if (sound[i].isPlaying()==true){
//                sound[i].stop();
//            }
//            //change the i == number when you add codes
//            if (i == 5 && unlock < 1){
//                unlock = -1;
//            }
//        }
//        resetClock++;
//    }
//    else if(resetClock>0){
//        if(resetClock<100){
//            resetClock++;
//        }
//        else{
//            resetClock=0;
//            keyCount=0;
//            unlock=0;
//        }
//    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    //ofDrawLine(ofGetWidth()/2, 0, ofGetWidth()/2, ofGetHeight());
    //graphical display
    font.drawString("Q: " + question[slide], ofGetWidth()/2, ofGetHeight()*0.4);
    font.drawString("A:", ofGetWidth()/2 - 60, ofGetHeight()*0.6 - 10);
    for(int i = 0; i<codeLength; i++){
        font.drawString(digit[i], ofGetWidth()/2 + i*20 - 30, ofGetHeight()*0.6);
    }
    if(unlock > 0){
        font.drawString("CODE ACCEPTED", ofGetWidth()/2, ofGetHeight()*0.65);
    }
    else if(unlock < 0){
        font.drawString("INCORRECT CODE", ofGetWidth()/2, ofGetHeight()*0.65);
    }
    font.drawString("Hint: " + clue[slide], ofGetWidth()/2, ofGetHeight()*0.8);
}

//--------------------------------------------------------------
void ofApp::exit(){
    printer.close();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    //cout << key << endl;
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
