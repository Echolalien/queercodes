#include <Keypad.h>
#include <Firmata.h>
#include <LiquidCrystal.h>

const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns
char keys[ROWS][COLS] = {
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'},
    {'*','0','#'}
};

byte ledPin = 13; 

boolean blink = false;
boolean ledPin_state;

byte rowPins[ROWS] = {8, 17, 18, 15}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {14, 9, 16}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

    //keypad input
    int keyCount;
    int pad [4];
    char digit[4];
        //declare codes
    char code [4][4] = {
    {'4', '0', '1', '2'}, //meds
    {'2', '9', '5', '7'}, //tie
    {'1', '3', '1', '2'}, //badge
    {'1', '9', '8', '5'}, //boot
    };
    
    int codeLength;   
    int resetClock; 
    int unlock;

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // put your setup code here, to run once:

  Firmata.begin(57600);
  Serial.begin(9600);
      pinMode(ledPin, OUTPUT);              // Sets the digital pin as output.
    digitalWrite(ledPin, HIGH);           // Turn the LED on.
    ledPin_state = digitalRead(ledPin);
  keypad.addEventListener(keypadEvent);

  lcd.begin(16, 2);

    codeLength = 4;
}

void loop() {
  // put your main code here, to run repeatedly:

    char key = keypad.getKey();

    if (key) {
            if(keyCount<codeLength){
                pad[keyCount]=key;
            keyCount++;
        }
    }
    if (blink){
        digitalWrite(ledPin,!digitalRead(ledPin));    // Change the ledPin from Hi2Lo or Lo2Hi.
        delay(100);
    }

  lcd.setCursor(0,1);

    for(int i = 0; i<4; i++){
        if(i<keyCount){
            digit[i] = "*";
            lcd.print("*");
        }
        else{
            digit[i] = "_";
            lcd.print("_");
        }
    }

    if(keyCount==codeLength && resetClock==0){
        int solve = 0;
        for(int i = 0; i<4; i++){
            for(int j = 0; j<4; j++){
                if(pad[j]==code[i][j]){
                    solve++;
                }
            }
            if(solve==codeLength){
                unlock=i+1;
                Serial.print(unlock);

            }
            solve=0;
        }
        resetClock++;
    }
    else if(resetClock>0){
        if(resetClock<200){
            resetClock++;
            if(unlock>0){
                lcd.setCursor(0,0);
                lcd.print("CODE ACCEPTED");
            }
            else{
                lcd.setCursor(0,0);
                lcd.print("INCORRECT CODE");
            }
        }
        else{
            resetClock=0;
            keyCount=0;
            unlock=0;
            lcd.clear();
        }
    }
    else{
        lcd.setCursor(0,0);
        lcd.print("Submit Code:");
    }
}

void keypadEvent(KeypadEvent key){
    switch (keypad.getState()){
    case PRESSED:
        if (key == '#') {
            digitalWrite(ledPin,!digitalRead(ledPin));
            ledPin_state = digitalRead(ledPin);        // Remember LED state, lit or unlit.
        }
        break;

    case RELEASED:
        if (key == '*') {
            digitalWrite(ledPin,ledPin_state);    // Restore LED state from before it started blinking.
            blink = false;
        }
        break;

    case HOLD:
        if (key == '*') {
            blink = true;    // Blink the LED when holding the * key.
        }
        break;
    }
}
