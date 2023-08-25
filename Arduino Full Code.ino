const int trigPin = 9;
const int echoPin = 10;
const int buzzer = 8;
const int ledPin = 11;

// defines variables
long duration;
int distance;
int safetyDistance;

//LDR SENSOR

int LDR =A0;
int led=13;
int threshold=40;

//GAS SENSOR

int greenLed = 2;
int Buzzer= 8;
int smokeA0 = A5;
// Your threshold value
int sensorThres = 400;

void setup()
{
  //LDR SENSOR
  
  Serial.begin(9600);
  pinMode(led,OUTPUT);
  //ULTRASONIC
  
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
pinMode(buzzer, OUTPUT);
pinMode(ledPin, OUTPUT);
Serial.begin(9600);

//GAS SENSOR

pinMode(Buzzer,OUTPUT);
  pinMode(smokeA0, INPUT);
  Serial.begin(9600);
  
}
void loop(){
  
  //LDR SENSOR
  
 int val=analogRead(LDR);
 Serial.print("value=");
  Serial.print(val);
 if(val<=threshold){
  digitalWrite(led,HIGH);
  delay(1000);
  
 }
 else{
  digitalWrite(led,LOW);
  delay(1000);
 }
 
 //ULTRASONIC
 
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

safetyDistance = distance;
if (safetyDistance <=5){
  digitalWrite(buzzer, HIGH);
  digitalWrite(ledPin, HIGH);
}
else{
  digitalWrite(buzzer, LOW);
  digitalWrite(ledPin, LOW);
}

// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);

//GAS SENSOR

 int analogSensor = analogRead(smokeA0);

  Serial.print("Pin A0: ");
  Serial.println(analogSensor);
  // Checks if it has reached the threshold value
  if (analogSensor > sensorThres)
  {
    tone(buzzer, 1000, 200);
  }
  else
  {
    noTone(buzzer);
  }
  delay(100);
}