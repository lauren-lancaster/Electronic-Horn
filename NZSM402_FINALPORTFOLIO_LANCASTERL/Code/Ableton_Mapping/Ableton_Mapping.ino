void setup() {
  
}

void loop() {
  
  int potVal = analogRead(A1); //read analog pin
  potVal = map(potVal, 0, 1023, 127, 0); //map values to midi
  
  usbMIDI.sendControlChange(15, (potVal), 1); //send to ableton
  Serial.println(potVal); //check value in serial 
  delay(100);
  
}
