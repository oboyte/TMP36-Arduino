# Arduino Temperature Sensor Library (TMP36)

This is a simple library used to simplify retrieving data from the TMP36 temperature sensor that comes along with the Arduino Starterkit. Note that this library only works with the Arduino framework, as it depends on Arduino functions. <br />
This does not only work on Arduino boards, this may be used on an ESP32 board (for example) as well, as long as you include the Arduino framework. <br />

A list of functions that the library provides: <br />
- <sub>setVCC(NUM)</sub>
    - Tells the object what voltage the VCC uses. This is very important to use after first initializing the object. Alternatively you could use the constructor for more advanced users. NOTE!! You have to set it in millivolts, so for 5v, you type in 5000. If you are stupid and set it to a number below 10, then there is a check in the function that will multiply it with 1000, however use millivolts as thats what the library is designed to use. 

- getVCC()
    - Returns what the VCC is set to.

- setPort(A{NUM})
    - Another important function to use after initializing the object. This here you need to type Analog port that the TMP36 uses. This is so that the microcontroller knows what port it will read to get the data the temperature sensor provides.

- getPort()
    - Returns the port used for the temperature sensor.

- getReading()
    - Returns the raw data the sensor sends to the analog port.

- getVoltage()
    - Transforms the raw data into voltage sent by the sensor.

- getTemperature()
    - Transforms the voltage into a temperature (as a float).
