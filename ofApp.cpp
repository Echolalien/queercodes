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
    message[0][0] =  ofBufferFromFile("text1_1.txt");
//    message[0][1] =  ofBufferFromFile("text1_1.txt");
//    message[0][2] =  ofBufferFromFile("text1_1.txt");
    message[1][0] =  ofBufferFromFile("text2_1.txt");
    message[1][1] =  ofBufferFromFile("text2_2.txt");
    message[1][2] =  ofBufferFromFile("text2_3.txt");
    message[2][0] =  ofBufferFromFile("text3_1.txt");
//    message[2][1] =  ofBufferFromFile("text3_1.txt");
//    message[2][2] =  ofBufferFromFile("text3_1.txt");
    message[3][0] =  ofBufferFromFile("text4_1.txt");
    message[3][1] =  ofBufferFromFile("text4_2.txt");
    message[3][2] =  ofBufferFromFile("text4_3.txt");
    message[4][0] =  ofBufferFromFile("text5_1.txt");
//    message[4][1] =  ofBufferFromFile("text5_1.txt");
//    message[4][2] =  ofBufferFromFile("text5_1.txt");
    message[5][0] =  ofBufferFromFile("text6_1.txt");
    message[5][1] =  ofBufferFromFile("text6_2.txt");
    message[5][2] =  ofBufferFromFile("text6_3.txt");
    message[6][0] =  ofBufferFromFile("text7_1.txt");
//    message[6][1] =  ofBufferFromFile("text7_1.txt");
//    message[6][2] =  ofBufferFromFile("text7_1.txt");
    message[7][0] =  ofBufferFromFile("text8_1.txt");
    message[7][1] =  ofBufferFromFile("text8_2.txt");
    message[7][2] =  ofBufferFromFile("text8_3.txt");
    message[8][0] =  ofBufferFromFile("text9_1.txt");
    message[8][1] =  ofBufferFromFile("text9_2.txt");
//    message[8][2] =  ofBufferFromFile("text9_2.txt");
    message[9][0] =  ofBufferFromFile("text10_1.txt");
    message[9][1] =  ofBufferFromFile("text10_2.txt");
//    message[9][2] =  ofBufferFromFile("text10_2.txt");
    
    
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
    question[0] = "Home to one of the largest LGBTIQ+ communities in Britain, Brighton’s population was disproportionately affected by the HIV virus.";
    overflow[0] = "What year did the Sunday Mirror run with the headline 'AIDS: Seaside Shocker'?";
    question[1] = "In what year did the homophobic legislation, Section 28, come into effect?";
    question[2] = "‘Brighton Head and Freak Magazine’ published a poem by Bill Butler which";
    overflow[2] = "is purported to be about ‘cottaging’. In what year was the poem published?";
    question[3] = "What year did Anne Lister stay in Brighton?";
    question[4] = "Brighton’s gay pride started as a protest in 1972. A full pride march took";
    overflow[4] = "place in 1973 but pride didn’t return to the city officially  until what year?";
    question[5] = "Brighton is host to the largest Trans Pride in the UK. What year did it start?";
    question[6] = "What year was Brighton’s first Big Drag Pageant?";
    question[7] = "In what year was the 'Queer in Brighton' anthology published?";
    question[8] = "The Rotimi Fani-Kayode reproduction is a rare example of local";
    overflow[8] = "queer black history. In what year was their ‘Under the Surface’ photo taken?";
    question[9] = "For 24 years, Brighton Ourstory collected and archived material";
    overflow[9] = "related to queer history in Brighton. What year was it founded?";
    
    //audio samples
    sound[0][0].load("audio1_1.mp3");
    sound[1][0].load("audio2_1.mp3");
    sound[2][0].load("audio3_1.mp3");
//    sound[3][0].load("audio4_1.mp3");
//    sound[4][0].load("audio5_1.mp3");
//    sound[5][0].load("audio6_1.mp3");
//////    sound[6][0].load("audio7_1.mp3");
////    sound[7][0].load("audio8_1.mp3");
////    sound[8][0].load("audio9_1.mp3");
////    sound[9][0].load("audio10_1.mp3");
////////    sound[0][1].load("audio1_1.mp3");
//////    sound[1][1].load("audio2_2.mp3");
////////    sound[2][1].load("audio3_1.mp3");
////////    sound[3][1].load("audio4_1.mp3");
////////    sound[4][1].load("audio5_1.mp3");
//////    sound[5][1].load("audio6_2.mp3");
////////    sound[6][1].load("audio7_1.mp3");
//////    sound[7][1].load("audio8_2.mp3");
//////    sound[8][1].load("audio9_2.mp3");
////////    sound[9][1].load("audio10_1.mp3");
////////    sound[0][2].load("audio1_1.mp3");
////////    sound[1][2].load("audio2_2.mp3");
////////    sound[2][2].load("audio3_1.mp3");
//////    sound[3][2].load("audio4_3.mp3");
////////    sound[4][2].load("audio5_1.mp3");
////////    sound[5][2].load("audio6_3.mp3"); THIS
////////    sound[6][2].load("audio7_1.mp3");
//////    sound[7][2].load("audio8_3.mp3");
////////    sound[8][2].load("audio9_2.mp3");
////////    sound[9][2].load("audio10_1.mp3");

    //serial
    mySerial.setup("/dev/ttyACM0", 9600);

    //LCD
    
    //speakers

//    //printer
    printer.open("/dev/serial0");
    printer.println("\n\nPrinter initialised");

    //hdmi output
    enigmaScale = 0.2;
    breakerScale = 0.2;
    ofSetBackgroundColor(0);
    font.load("arial", 20, true, true, false);
    ofSetColor(255);
    breaker.load("breaker.png");
    breaker.resize(breaker.getWidth() * breakerScale, breaker.getHeight() * breakerScale);
    enigma.load("enigma.png");
    enigma.resize(enigma.getWidth() * enigmaScale, enigma.getHeight() * enigmaScale);
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
            digit[i] = ofToString(pad[i]);
        }
        else{
            digit[i] = "_";
        }
    }

    //solve check
    if(keyCount==codeLength && resetClock==0){
        solve = (pad[0]*1000)+(pad[1]*100)+(pad[2]*10)+pad[3];
        for(int i = 0; i<10; i++){ //there'll be a memory leak here if u add codes but don't update that number of iterations lol
            if(solve==code[i]){
                unlock=i+1;
                int roulette = (int) ofRandom(3);
                bool blank;
                if(!message[i][roulette].getText().empty()){
                    cout << "\nPrinting:\n" + message[i][roulette].getText()<< endl;
                    printer.println("Queer Codebreakers\nQueer the Pier Exhibition 2020\n\n");
                    printer.println(message[i][roulette]);
                    printer.println("\n\nExcerpt from Queer in Brighton oral history collection.");
                }
                else{
                    blank = true;
                }
                if(sound[i][roulette].isLoaded()==true){
                    sound[i][0].stop();
                    sound[i][1].stop();
                    sound[i][2].stop();
                    sound[i][roulette].play();
                }
                else if(blank == true){
                    if(sound[i][0].isLoaded()==true){
                        sound[i][0].stop();
                        sound[i][1].stop();
                        sound[i][2].stop();
                        sound[i][0].play();
                    }
                    if(!message[i][0].getText().empty()){
                        cout << "\nPrinting:\n" + message[i][0].getText()<< endl;
                        printer.println("Queer Codebreakers\nQueer the Pier Exhibition 2020\n\n");
                        printer.println(message[i][0]);
                        printer.println("\n\nExcerpt from Queer in Brighton oral history collection.");
                    }
                }
            }

            else if (sound[i][0].isPlaying()==true || sound[i][1].isPlaying()==true || sound[i][2].isPlaying()==true){
                sound[i][0].stop();
                sound[i][1].stop();
                sound[i][2].stop();
            }
            
        }
        resetClock++;
        if(unlock<1) unlock = -1;
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
    //ofDrawLine(ofGetWidth()/2, 0, ofGetWidth()/2, ofGetHeight());
    //graphical display
    breaker.draw(ofGetWidth()/1.5, ofGetHeight()/2);
    enigma.draw(ofGetWidth()/60, ofGetHeight()/2.2);
    font.drawStringCentered("Q: " + question[slide], ofGetWidth()/2, ofGetHeight()*0.4);
        font.drawStringCentered(overflow[slide], ofGetWidth()/2, ofGetHeight()*0.43);   font.drawStringCentered("A:", ofGetWidth()/2 - 60, ofGetHeight()*0.6 - 10);
    for(int i = 0; i<codeLength; i++){
        font.drawStringCentered(digit[i], ofGetWidth()/2 + i*20 - 30, ofGetHeight()*0.591);
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
