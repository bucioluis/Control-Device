// Name your states
#define OFF 0
#define ON 1
#define BLINK 2

#define BUTTON_PIN 2
#define LED_OUTPUT 13
#define DEBOUNCE_DELAY 100
#define BLINK_DELAY 1000

#define INIT 0
#define RUN 1
#define EXIT 2
int deviceState = OFF;
unsigned long timestamp;

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED_OUTPUT, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if(digitalRead(BUTTON_PIN) == LOW) {
    delay(100);
    if(digitalRead(BUTTON_PIN) == LOW) {
      deviceState ++;
      deviceState = deviceState % 3;
      timestamp = millis();
      Serial.println(deviceState);
    }
  }

  if (deviceState == OFF) {
   digitalWrite(LED_OUTPUT, OFF);
 }
  if (deviceState == ON) {
   digitalWrite(LED_OUTPUT, ON);
 }
  if (deviceState == BLINK) {
    if (millis() - timestamp > BLINK_DELAY) {
      digitalWrite(LED_OUTPUT, !digitalRead(LED_OUTPUT));
      timestamp = millis();
    }

      //old way of doing them
 //if(digitalRead(BUTTON_PIN) == LOW) {
    //if(digitalRead(BUTTON_PIN) == LOW) {
      //delay(100);
      //if(digitalRead(BUTTON_PIN) == LOW) {
        //deviceState ++;
        //deviceState = deviceState % 3;
        //Serial.println(deviceState);
  //delay(DEBOUNCE_DELAY);
  //if(!digitalRead(BUTTON_PIN)) {
  // debounce sanctum
  //}
  //}
  //digitalWrite(LED_OUTPUT, HIGH);
    //delay(BLINK_DELAY);
    //digitalWrite(LED_OUTPUT, LOW);
    //delay(BLINK_DELAY);
  }
 }

 // alternate way to write the code block above
 /*if (deviceState != BLINK) {
  digitalWrite(LED, deviceState);
  }

  if (deviceState == BLINK)  {
  digitalWrite(LED, HIGH);
  delay(BLINK_DELAY);
  digitalWrite(LED, LOW);
  delay(BLINK_DELAY);
  } */
