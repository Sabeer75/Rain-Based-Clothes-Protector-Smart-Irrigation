#include <Servo.h>

#define RAIN_PIN 2
#define SERVO_PIN 9
#define SOIL_PIN A0
#define BUZZER_PIN 6
#define RELAY_PIN 8

Servo clothServo;

int soilThreshold = 400;

void setup() {
  pinMode(RAIN_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(RELAY_PIN, OUTPUT);

  digitalWrite(RELAY_PIN, HIGH); 

  clothServo.attach(SERVO_PIN);
  clothServo.write(0);

  Serial.begin(9600);
}

void loop() {
  rainSystem();
  irrigationSystem();
}

void rainSystem() {
  int rain = digitalRead(RAIN_PIN);

  if (rain == LOW) {       
    clothServo.write(90);  
  } else {
    clothServo.write(0);  
  }
}

void irrigationSystem() {
  int soil = analogRead(SOIL_PIN);
  Serial.println(soil);

  if (soil > soilThreshold) {
    digitalWrite(RELAY_PIN, LOW);    
    digitalWrite(BUZZER_PIN, HIGH);  
  } else {
    digitalWrite(RELAY_PIN, HIGH);  
    digitalWrite(BUZZER_PIN, LOW); 
  }
}

