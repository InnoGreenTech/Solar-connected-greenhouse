Solar connected greenhouse Atmega 2560 Software
===============================================

Liraries use:
-------------

#include <DHT.h>
#include <OneWire.h>
#include <DS18B20.h>
#include <NewPing.h>
#include <printf.h>
#include <registers.h> 
#include <pin_magic.h>
#include <Servo.h>

Library modifications:
----------------------

#include <DS18B20.h>:

The time acquisition is really too long to have a good fluidity, i have desactivate this delay on line 57 and read the last get 
before to do a new one. This is in file DS18B20.
		
	float DS18B20::getTempC() {
    		sendCommand(MATCH_ROM, CONVERT_T, !selectedPowerMode);
    		//delayForConversion(selectedResolution, selectedPowerMode);
    		readScratchpad();
    		uint8_t lsb = selectedScratchpad[TEMP_LSB];
    		uint8_t msb = selectedScratchpad[TEMP_MSB];

    		switch (selectedResolution) {
        		case 9:
            			lsb &= 0xF8;
            			break;
        		case 10:
            			lsb &= 0xFC;
            			break;
        		case 11:
            			lsb &= 0xFE;
            			break;
    			}

    		uint8_t sign = msb & 0x80;
    		int16_t temp = (msb << 8) + lsb;

    		if (sign) {
        		temp = ((temp ^ 0xffff) + 1) * -1;
    		}	
	
	sendCommand(MATCH_ROM, CONVERT_T, !selectedPowerMode);
    	//delayForConversion(selectedResolution, selectedPowerMode);

    	return temp / 16.0;
	}

#include <Servo.h>

This library is include with the IDE Arduino. I use the pin 46 PWM, but the servo.h use the same timer than the PWM. I need to change this. It need to do the modification on the file avr/SevoTimer.h line 39.
I have inverted _timer1 and _timer5

	typedef enum { _timer1, _timer5, _timer3, _timer4, _Nbr_16timers } timer16_Sequence_t;