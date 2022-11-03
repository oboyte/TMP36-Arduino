#include <Arduino.h>
#include <TMP.h>

TMP36 tmp;

void setup() {
  Serial.begin(9600);
  tmp.setVCC(5000); //Tells microcontroller that it is a 5V vcc circuit. This example was in Arduino UNO, if you use a board that uses 3.3V, type instead 3300.
  tmp.setPort(A0); //Tells microcontroller to check Analog 0 port for the temp sensor readings. 

}

void loop() {
  int reading = tmp.getReading(); // Returns raw data the temperatur sensor sends, stores it in reading variable. 
  int voltage = tmp.getVoltage(); // Transforms the raw data into voltage.
  float temperature = tmp.getTemperature(); // Transforms the voltage into temperature.
  

  Serial.print("Reading is: "); Serial.println( reading );
  Serial.print("Voltage is: "); Serial.println( voltage );
  Serial.print("Temperature is: "); Serial.println( temperature );
  delay(1000);
  
}
