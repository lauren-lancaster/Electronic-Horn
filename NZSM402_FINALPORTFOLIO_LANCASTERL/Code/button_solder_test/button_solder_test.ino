int pushButton1 = 1; //read digital input pin 2
int pushButton2 = 2; //read digital input pin 3
int pushButton3 = 3; 
int pushButton4 = 10; 
int pushButton5 = 11; 
int pushButton6 = 12; 
int prevValue1 = 0;
int prevValue2 = 0;
int prevValue3 = 0;
int prevValue4 = 0;
int prevValue5 = 0;
int prevValue6 = 0;


void setup() {
  // put your setup code here, to run once:
  pinMode(pushButton1, INPUT_PULLUP); //make pushbutton pin an input
  pinMode(pushButton2, INPUT_PULLUP); 
  pinMode(pushButton3, INPUT_PULLUP); 
  pinMode(pushButton4, INPUT_PULLUP); 
  pinMode(pushButton5, INPUT_PULLUP); 
  pinMode(pushButton6, INPUT_PULLUP); 
  pinMode(13, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int buttonState1 = digitalRead(pushButton1); //read input pin
  int buttonState2 = digitalRead(pushButton2); 
  int buttonState3 = digitalRead(pushButton3); 
  int buttonState4 = digitalRead(pushButton4); 
  int buttonState5 = digitalRead(pushButton5); 
  int buttonState6 = digitalRead(pushButton6); 

  if(buttonState1 == 0 && prevValue1 == 1) {
    Serial.println(buttonState1);
    digitalWrite(13, HIGH); //checks its working with teensy led
  }

   if(buttonState1 == 1 && prevValue1 == 0) {
    Serial.println(buttonState1);
    digitalWrite(13, LOW); //checks its working with teensy led
  }

  if(buttonState2 == 0 && prevValue2 == 1) {
    
    digitalWrite(13, HIGH); //checks its working with teensy led
  }

  if(buttonState2 == 1 && prevValue2 == 0) {
    
    digitalWrite(13, LOW); //checks its working with teensy led
  }

  if(buttonState3 == 0 && prevValue3 == 1) {
    
    digitalWrite(13, HIGH); //checks its working with teensy led
  }

  if(buttonState3 == 1 && prevValue3 == 0) {
    
    digitalWrite(13, LOW); //checks its working with teensy led
  }

  if(buttonState4 == 0 && prevValue4 == 1) {
    
    digitalWrite(13, HIGH); //checks its working with teensy led
  }

   if(buttonState4 == 1 && prevValue4 == 0) {
    
    digitalWrite(13, LOW); //checks its working with teensy led
  }

  if(buttonState5 == 0 && prevValue5 == 1) {
    
    digitalWrite(13, HIGH); //checks its working with teensy led
  }

  if(buttonState5 == 1 && prevValue5 == 0) {
    
    digitalWrite(13, LOW); //checks its working with teensy led
  }

  if(buttonState6 == 0 && prevValue6 == 1) {
    
    digitalWrite(13, HIGH); //checks its working with teensy led
  }

  if(buttonState6 == 1 && prevValue6 == 0) {
    
    digitalWrite(13, LOW); //checks its working with teensy led
  }
//SET PREV VALUES TO BUTTON STATES
  prevValue1 = buttonState1; 
  prevValue2 = buttonState2;
  prevValue3 = buttonState3;
  prevValue4 = buttonState4;
  prevValue5 = buttonState5;
  prevValue6 = buttonState6;

  delay(200);


}
