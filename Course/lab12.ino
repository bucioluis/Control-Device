// 15 Nov 2017 Lab before Thanksgiving Break
// Learned about 
// Volatile
// Interrupt Service Routine
// Vector

const byte ledPin = 11;
const byte interruptPin = 2;
volatile byte state = LOW;

void setup(){
  pinMode(ledPin, OUTPUT);
  pinMode(interrupt, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin), blink, CHANGE);
}

void loop(){
  digitalWrite(ledPin, state);
}

void blink(){
  state = !state;
}
