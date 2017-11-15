11unsigned long timestamp;


void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  // poll for button push
// increment stae if button push is legit
  if(digitalRead(BUTTON) == LOW) {
    delay(100);
    if(digitalRead(BUTTON) == LOW) {
      state ++;
      state = state % 3;
      tiemstampe = millis();
    }
  }
  if (state == OFF) {
      digitalWrite(LED, OFF);
  }
  
  if (state == ON) {
      digitalWrite(LED, ON);
  }
  
 if (state == BLINK) {
  if (millis() - timestamp > BLINK_DELAY) {
    digitalWrite(LED, !digitalRead(LED));
    timestamp = millis();
  }
 
 //digitalWrite(LED, HIGH);
 //delay(100);
 //for(unsigned long i = 0; i< 1000000; i++) {}
 //digitalWrite(LED LOW);
 //delay(100);
}

}
