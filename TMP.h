#ifndef TMP
#define TMP

#include <Arduino.h>

class TMP36 {

private:
    int m_vcc { };
    uint8_t m_analogPort { };
    float m_temperature { };
    float m_voltage { };
    int m_reading;


public:
    //Constructor
    TMP36(int vcc=0, uint8_t analogPort = 0);



    //Set the VCC in MILLIVOLTS! (Arduino UNO is 5000mv, ESP32 is 3300mv)
    void setVCC(float vcc);

    //Return VCC voltage that you set
    int getVCC();



    //Set the port to whatever port the Analog voltage out pin is connected to. (Has to be an Analog port). 
    void setPort(uint8_t analogPort); 

    //Return the analog port you set.
    uint8_t getPort();



    //Returns the raw data the TMP36 sends to the port. 
    int getReading();

    //Returns the voltage measured.
    float getVoltage();

    //Returns the temperature. 
    float getTemperature();



};

#endif
