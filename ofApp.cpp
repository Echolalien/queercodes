#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    //give codes
    codeLength = 4;
    code[0] = 1985;
    code[1] = 1988;
    code[2] = 1968;
    code[3] = 1826;
    code[4] = 1991;
    code[5] = 2013;
    code[6] = 2018;
    code[7] = 2014;
    code[8] = 1987;
    code[9] = 1989;

    //give transcripts to output to printer
    message[0] =  ofBufferFromFile("transcript0.txt");
    message[1] =  ofBufferFromFile("transcript1.txt");
    message[2] =  ofBufferFromFile("transcript2.txt");
    message[3] =  ofBufferFromFile("transcript3.txt");
    message[4] =  ofBufferFromFile("transcript4.txt");
    message[5] =  ofBufferFromFile("transcript5.txt");
    message[6] =  ofBufferFromFile("transcript6.txt");
    message[7] =  ofBufferFromFile("transcript7.txt");
    message[8] =  ofBufferFromFile("transcript8.txt");
    message[9] =  ofBufferFromFile("transcript9.txt");
    
    //give clues
    clue[0] = "Look in the house of horrors";
    clue[1] = "";
    clue[2] = "Look in the artist and writers cabinet -enter earliest year stated";
    clue[3] = "Anne Lister wrote about it in her diary";
    clue[4] = "";
    clue[5] = "";
    clue[6] = "Watch the film about performance and drag";
    clue[7] = "";
    clue[8] = "Look in the library section!";
    clue[9] = "";
    
    //give questions
    question[0] = "Home to one of the largest LGBTIQ+ communities in Britain, Brighton’s population was disproportionately affected by the HIV virus.\nWhat year did the Sunday Mirror run with the headline 'AIDS: Seaside Shocker'?";
    question[1] = "In what year did the homophobic legislation, Section 28, come into effect?";
    question[2] = "‘Brighton Head and Freak Magazine’ published a poem by Bill Butler which\nis purported to be about ‘cottaging’. In what year was the poem published?";
    question[3] = "What year did Anne Lister stay in Brighton?";
    question[4] = "Brighton’s gay pride started as a protest in 1972.\nA full pride march took place in 1973 but pride didn’t return to\nthe city officially  until what year?";
    question[5] = "Brighton is host to the largest Trans Pride in the UK. What year did it start?";
    question[6] = "What year was Brighton’s first Big Drag Pageant?";
    question[7] = "In what year was the 'Queer in Brighton' anthology published?";
    question[8] = "The Rotimi Fani-Kayode reproduction is a rare example of local queer black history.\nIn what year was their ‘Under the Surface’ photo taken?";
    question[9] = "For 24 years, Brighton Ourstory collected and archived material\nrelated to queer history in Brighton. What year was it founded?";
    
    //audio samples
//    sound[0].load("audio0.wav");
//    sound[1].load("audio1.wav");
    sound[2].load("audio2.wav");
//    sound[3].load("audio3.wav");
//    sound[4].load("audio4.wav");
//    sound[5].load("audio5.wav");
//    sound[6].load("audio6.wav");
//    sound[7].load("audio7.wav");
//    sound[8].load("audio8.wav");
//    sound[9].load("audio9.wav");

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
//    if ( myByte == OF_SERIAL_NO_DATA ){
//        //comment this out if you want your code to be legible
//        //printf("no data was read\n");
//    }
//    else if ( myByte == OF_SERIAL_ERROR ){
////        printf("an error occurred\n");
//    }
    if ( myByte >= 48 && myByte < 58 && keyCount<codeLength){
        //cout << myByte-48 << endl;
        myByte-=48;
        pad[keyCount]=myByte;
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

    //solve check
    if(keyCount==codeLength && resetClock==0){
        solve = (pad[0]*1000)+(pad[1]*100)+(pad[2]*10)+pad[3];
        for(int i = 0; i<6; i++){ //there'll be a memory leak here if u add codes but don't update that number of iterations lol
            if(solve==code[i]){
                unlock=i+1;
                cout << "printing: " + message[i].getText()<< endl;
                printer.println(message[i]);
                if(sound[i].isLoaded()==true){
                    sound[i].play();
                }
            }

            else if (sound[i].isPlaying()==true){
                sound[i].stop();
            }
            //change the i == number when you add codes
            if (i == 5 && unlock < 1){
                unlock = -1;
            }
        }
        resetClock++;
    }
    else if(resetClock>0){
        if(resetClock<100){
            resetClock++;
        }
        else{
            resetClock=0;
            keyCount=0;
            unlock=0;
        }
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofDrawLine(ofGetWidth()/2, 0, ofGetWidth()/2, ofGetHeight());
    //graphical display
    //add header print
    font.drawStringCentered("Q: " + question[slide], ofGetWidth()/2, ofGetHeight()*0.4);
    font.drawStringCentered("A:", ofGetWidth()/2 - 60, ofGetHeight()*0.6 - 10);
    for(int i = 0; i<codeLength; i++){
        font.drawStringCentered(digit[i], ofGetWidth()/2 + i*20 - 30, ofGetHeight()*0.6);
    }
    if(unlock > 0){
        font.drawStringCentered("CODE ACCEPTED", ofGetWidth()/2, ofGetHeight()*0.65);
    }
    else if(unlock < 0){
        font.drawStringCentered("INCORRECT CODE", ofGetWidth()/2, ofGetHeight()*0.65);
    }
    font.drawStringCentered("Hint: " + clue[slide], ofGetWidth()/2, ofGetHeight()*0.8);
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
    if ( key == 110){
        if(slide < clueNum-1){
            slide++;
        }
        else{
            slide = 0;
        }
    }
}
