#include "TMP.h"

TMP36::TMP36(int vcc, uint8_t analogPort)
    : m_vcc { vcc }, m_analogPort { analogPort }
{
}

//Set the VCC in MILLIVOLTS! (Arduino UNO is 5000mv, ESP32 is 3300mv)
void TMP36::setVCC(float millivolt) {
    
    if (millivolt < 10) 
    {
        millivolt *= 1000;
    }

    m_vcc = millivolt;
}

//Get VCC voltage that you set
int TMP36::getVCC() {
    return m_vcc;
}



//Set the port to whatever port the Analog voltage out pin is connected to. (Has to be an Analog port). 
void TMP36::setPort(uint8_t sensorPin) {
    m_analogPort = sensorPin;
}

//Get the analog port you set.
uint8_t TMP36::getPort() {
    return m_analogPort;
}



//Returns the raw data the TMP36 sends to the port. 
int TMP36::getReading() {
    m_reading = analogRead(m_analogPort);

    return m_reading;
}

//Get the voltage measured
float TMP36::getVoltage() {

    int reading = TMP36::getReading();

    float volt { (float)reading * ((float)m_vcc / 1024.f) };

    m_voltage = volt;

    return m_voltage;
}

//Get the temperature measured. 
float TMP36::getTemperature() {

    float voltage = TMP36::getVoltage();
    
    float temperature { (voltage - 500.f) / 10.f };
    
    m_temperature = temperature;
    
    return m_temperature;
}
