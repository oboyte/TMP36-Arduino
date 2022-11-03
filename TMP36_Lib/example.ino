#include <Arduino.h>
#include "TMP.h"

TMP36 tempSensor;


void setup() {
  // put your setup code here, to run once:
  tempSensor.setVCC(5000); //This example runs on Arduino Uno, so the VCC will be 5 volts.
  tempSensor.setPort(A0); //Tells the microcontroller that the reading will be on A0.
}

void loop() {
  int reading = tempSensor.getReading();
  int voltage = tempSensor.getVoltage();
  float temperature = tempSensor.getTemperature();
  

  Serial.println("Reading is: "); Serial.print( reading );
  Serial.println("Voltage is: "); Serial.print( voltage );
  Serial.println("Temperature is: "); Serial.print( temperature );


}