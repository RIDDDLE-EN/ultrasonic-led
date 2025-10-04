#include <Arduino.h>

const int triggerPin = 7;
const int echoPin = 6;
const int ledPin = 8;

const long threshold = 30;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);

  Serial.begin(9600);
  Serial.println("Ultrasonic Sensor Test");
}
void loop() {
  // put your main code here, to run repeatedly:
  //send a 10 microsecond pulse to triggerPin
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  //read the echoPin, returns the sound wave travel time in microseconds
  long duration = pulseIn(echoPin, HIGH);
  //calculate the distance
  long distance = duration * 0.034 / 2; //cm
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  if (distance < threshold) {
    digitalWrite(ledPin, HIGH); // turn the LED on (HIGH is the voltage level)
  } else {
    digitalWrite(ledPin, LOW); // turn the LED off by making the voltage LOW
  }
  delay(100);
}