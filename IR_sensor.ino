/*======================================================
                       IR SENSOR
========================================================
Description:
This program reads the signal from an infrared (IR) sensor
module to detect the presence of an obstacle or measure 
proximity, and outputs the sensor readings and detection 
status to the Serial Monitor.

Programmer: 
  Sergie D. Gomez

Date: 
  14 October 2026
-----------------------------------------------------*/


const int OUT = 2;          
const int ledPin = 13;      

int Number_of_Object = 0;   
int SensorState = 0;        
int lastSensorState = HIGH; 

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(OUT, INPUT);
}
void loop() {
  SensorState = digitalRead(OUT);
  if (SensorState == LOW && lastSensorState == HIGH) {
    Number_of_Object++;
    digitalWrite(ledPin, HIGH);
    Serial.printf("Object detected! Total: %d\n", Number_of_Object);
    delay(200); 
  } else if (SensorState == HIGH) {
    digitalWrite(ledPin, LOW);
  }
  lastSensorState = SensorState;
}
