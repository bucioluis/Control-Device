/* Ardino Lab 4
 * Author Jose Bucio
 * Date 27 September 2017
 * 
 * 
 * Input Pullup and Debounce Lab
 * 
 * circuit Description:
 * 
 * Pin 2 (P/U)  ---------oTo----
 *                        switch
 *                              |
 *                              V
 *                             GND
 */
 
// const int buttonPin = 2;
#define BUTTON_PIN 2 // Not a C statement
                     // A preprossor direction
#define LED_OUTPUT 13
#define DEBOUNCE_DELAY 50

bool ledState = false;
bool switchState = false;
 
void setup() {
  // put your setup code here, to run once:
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED_OUTPUT, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
 // ledState = digitalRead(BUTTON_PIN); 
  switchState = digitalRead(BUTTON_PIN);
  if(switchState == LOW){
    delay(DEBOUNCE_DELAY);
    if(digitalRead(BUTTON_PIN) == LOW){
      ledState != ledState;
    }
  digitalWrite(LED_OUTPUT, ledState);
  
}
