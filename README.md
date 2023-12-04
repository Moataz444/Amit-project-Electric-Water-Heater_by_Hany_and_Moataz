# Amit-project-Electric-Water-Heater_by_Hany_and_Moataz
Graduation project for AMIT Embedded Diploma

Amit project: Electric Water Heater by Hany and Moataz

An Electric Water Heater that senses current temperature, and start heater if current temperature lower than set temperature by 5 degrees, and start cooler if current temperature higher than set temperature by 5 degrees.

    Used Components:
                    HAL:
                        1- Relay : for heater
                        2- Cooling Element (Fan)
                        3- Heating Element
                        4- 7-Segment
                        5- Push Buttons
                        6- Leds
                        7- Temperature Sensor (NTC Thermistor)
                        
                  MCAL:
                        1- DIO
                        2- GIE (Global Interrupt)
                        3- ADC : for temperature sensor
                        4- Timers (0,1,2) : for delays and Interrupts
                        5- EEPROM : for storing Set Temperature
