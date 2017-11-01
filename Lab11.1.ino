// Learn to create a blink

#define OFF 0
#define ON 1
#define BLINK 2

int deviceState = OFF;

void setup() {
  // put your setup code here, to run once:
  pinMode(BUTTON, INPUT_PULLUP);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(BUTTON) == LOW){
    delay(DEBOUNCE);
    if(digitalRead(BUTTON) == LOW) {
      //debounce sanctum
      deviceState++;
      deviceState = deviceState % 3;
      Serial.println(deviceState);
    }
 }
    
    if(deviceState != BLINK){
      digitalWrite(LED, deviceState);
    }
    if(deviceState == BLINK){
      deviceState(LED, HIGH);
      delay(BLINK_DELAY);
      deviceState(LED, LOW);
      delay(BLINK_DELAY);
    }
}
