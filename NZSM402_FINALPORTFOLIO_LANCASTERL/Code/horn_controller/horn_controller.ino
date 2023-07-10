int pushButton1 = 1; //read digital input pin 
int pushButton2 = 2; 
int pushButton3 = 3; 
int pushButton4 = 10; 
int pushButton5 = 11; 
int pushButton6 = 12; 
int prevValue1 = 0; //set previous value of digital read to 0
int prevValue2 = 0;
int prevValue3 = 0;
int prevValue4 = 0;
int prevValue5 = 0;
int prevValue6 = 0;
int stateValue1 = 0; //set stateValue of potentiometer to 0
int stateValue2 = 0;
int stateValue3 = 0;
int stateValue4 = 0;
int stateValue5 = 0;
int stateValue6 = 0;

void setup() {
  pinMode(pushButton1, INPUT_PULLUP); //make pushbutton pin an input + pull up resistor
  pinMode(pushButton2, INPUT_PULLUP); 
  pinMode(pushButton3, INPUT_PULLUP); 
  pinMode(pushButton4, INPUT_PULLUP); 
  pinMode(pushButton5, INPUT_PULLUP); 
  pinMode(pushButton6, INPUT_PULLUP); 
  pinMode(13, OUTPUT); //set LED pin to test LED on board
}

void loop() {
  int potVal1 = analogRead(A2); //read analog input pin 
  int potVal2 = analogRead(A6); 
  int buttonState1 = digitalRead(pushButton1); //read input pin
  int buttonState2 = digitalRead(pushButton2); 
  int buttonState3 = digitalRead(pushButton3); 
  int buttonState4 = digitalRead(pushButton4); 
  int buttonState5 = digitalRead(pushButton5); 
  int buttonState6 = digitalRead(pushButton6); 


  if(buttonState1 == 0 && prevValue1 == 1) { //if button1 on and was prev off
    usbMIDI.sendControlChange(7, 127, 1);  //note 7, velocity 127 (127 turns on), channel 1
    digitalWrite(13, HIGH); //checks working with teensy led
  }

   if(buttonState1 == 1 && prevValue1 == 0) { //if button1 off and prev on
    usbMIDI.sendControlChange(7, 0, 1);  //note 7, velocity 127 ( 0 turns off), channel 1
    digitalWrite(13, LOW); //teensy led off
  }

  if(buttonState2 == 0 && prevValue2 == 1) {
    usbMIDI.sendControlChange(8, 127, 1);  
    digitalWrite(13, HIGH); 
  }

  if(buttonState2 == 1 && prevValue2 == 0) {
    usbMIDI.sendControlChange(8, 0, 1);  
    digitalWrite(13, LOW); 
  }

  if(buttonState3 == 0 && prevValue3 == 1) {
    usbMIDI.sendControlChange(9, 127, 1);  
    digitalWrite(13, HIGH); 
  }

  if(buttonState3 == 1 && prevValue3 == 0) {
    usbMIDI.sendControlChange(9, 0, 1);  
    digitalWrite(13, LOW); 
  }


  if(buttonState4 == 0) { //if button 4 on read potentiometer
    //if(potVal1 - stateValue1 => 20 || potVal1 - stateValue1 => -20) {
    
    
    stateValue1 = map(potVal1, 0, 1023, 127, 0); //assign state to force pressure sensor 1 value
    usbMIDI.sendControlChange(10, (stateValue1), 1); //1023 max / 8 = 127 max in midi
    stateValue2 = map(potVal2, 0, 1023, 127, 0); //assign state to force pressure sensor 2 value
    usbMIDI.sendControlChange(11, (stateValue2), 1);
  }

  if(buttonState4 == 1) { //if button 4 OFF mantain last state value from button ON
    usbMIDI.sendControlChange(10, (stateValue1), 1);
    usbMIDI.sendControlChange(11, (stateValue2), 1);
  }

  if(buttonState5 == 0) {
    stateValue3 = map(potVal1, 0, 1023, 127, 0);
    usbMIDI.sendControlChange(12, (stateValue3), 1);
    stateValue4 = map(potVal2, 0, 1023, 127, 0);
    usbMIDI.sendControlChange(13, (stateValue4), 1);
  }

  if(buttonState5 == 1) {
    usbMIDI.sendControlChange(12, (stateValue3), 1);
    usbMIDI.sendControlChange(13, (stateValue4), 1);
  }

  if(buttonState6 == 0) {
    stateValue5 = map(potVal1, 0, 1023, 127, 0);
    usbMIDI.sendControlChange(14, (stateValue5), 1);
    stateValue6 = map(potVal2, 0, 1023, 127, 0);
    usbMIDI.sendControlChange(15, (stateValue6), 1);
  }

  if(buttonState6 == 1) {
    usbMIDI.sendControlChange(14, (stateValue5), 1);
    usbMIDI.sendControlChange(15, (stateValue6), 1);
  }


//set prev values to button states
  prevValue1 = buttonState1; 
  prevValue2 = buttonState2;
  prevValue3 = buttonState3;
  prevValue4 = buttonState4;
  prevValue5 = buttonState5;
  prevValue6 = buttonState6;

  delay(10); //delay loop 

}
