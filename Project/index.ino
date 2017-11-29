#define trigPin 8
#define echoPin 9
#define beepPin 10
#define scalingfactor 10

int inches = 0;
unsigned long duration = 0;
unsigned long maxtime = 1000;
unsigned long i = 1;
unsigned long time2 = 0;
unsigned long time1 = 0;

void setup()
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(beepPin, OUTPUT);
}

void logdistance()
{
  time1 = millis();
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  inches = duration/148;
  time2 = millis();
  maxtime = scalingfactor*inches;
}

void delayandcheckdistance(){
  i=1;
  while(1){
    if (i % 60 == 0){
      logdistance();
    }
    delay(1);
    ++i;
    if (i >= maxtime){
      break;
    }
  }
}

void beep()
{
  digitalWrite(beepPin, HIGH);
  delay(90);
  logdistance();
  if(time2-time1 < 30){
    delay(60-(time2-time1));
  }
  digitalWrite(beepPin, LOW);
}

void loop()
{
  beep();
  delayandcheckdistance();
}

// defines pins numbers
#define IN4  4
const int trigPin = 5;
const int echoPin = 6;

// defines variables
long duration;
int distance = 0;
void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  pinMode(4, OUTPUT);
  Serial.begin(9600); // Starts the serial communication
}

void loop() {
if ((distance <50)&&(distance > 0)) {
  digitalWrite(IN4, HIGH);   // turn the LED on (HIGH is the voltage level)
} 
  else if ((distance > 51)&&(distance < 150)) {
    digitalWrite(IN4, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(10*(distance-50));  
    digitalWrite(IN4, LOW);   // turn the LED on (HIGH is the voltage level)
    delay(10*(distance-50));// wait for a set time
  }
  else if ((distance > 151)&&(distance < 200)) {
    digitalWrite(IN4, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(1000);  
    digitalWrite(IN4, LOW);   // turn the LED on (HIGH is the voltage level)
    delay(1000);
}
  else if (distance > 200){
    digitalWrite(IN4, LOW);
}

delayMicroseconds(10);

// Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);

// Calculating the distance
distance= duration*0.034/2;

// Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance); //distance is the returned integer, it is the distance in cm

}
