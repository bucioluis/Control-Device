
int buttonInput = 2;
int lightOutput = 13;
int buttonState = 0;

void setup(){

    pinMode(lightOutput, OUTPUT);
    pinMode(buttonInput, INPUT);
    digitalWrite(button, HIGH);
}

void loop(){
  buttonState = digitalRead(buttonInput);
  if(buttonState == HIGH){
    digitalWrite(lightOutput, LOW);
  }
  else{
    digitalWrite(lightOutput, HIGH);
  }
}
