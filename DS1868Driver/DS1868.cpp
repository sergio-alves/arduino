#include "DS1868.h"

DS1868::DS1868()
{

}

void DS1868::begin(byte rstPin, byte clkPin, byte datPin) {
	DS1868::rstPin = rstPin;
	DS1868::clkPin = clkPin;
	DS1868::datPin = datPin;

	/* IOs used to control the digital pot that controls the opamp gain */
	pinMode(rstPin, OUTPUT);
	pinMode(clkPin, OUTPUT);
	pinMode(datPin, OUTPUT);
	digitalWrite(rstPin, LOW);
	digitalWrite(clkPin, LOW);
	digitalWrite(datPin, LOW);
}

DS1868::~DS1868()
{
}

/*
Send 17 bits of data to the DS1868 IC to set trimmers whipers
*/
void DS1868::setTrims() {
	byte bit;
  if(&logger) 
    logger.debug(F("Pot values (0, 1) -> (%i, %i)"), trim1, trim2);

	//stop reset
	digitalWrite(rstPin, HIGH);
	delayMicroseconds(1);    
	transmitBit(0);
	transmitByte(trim1);
	transmitByte(trim2);
	digitalWrite(rstPin, LOW);

  //print message
   if(&logger)
    logger.info(F("Trimers set"));
}


/*
Send a bit to the ds1868 IC
set clock pin to low then set the data pin and set clock pin high again,
*/
void DS1868::transmitBit(byte bit) {
	digitalWrite(clkPin, LOW);
	delayMicroseconds(1);
	digitalWrite(datPin, bit);
	delayMicroseconds(1);
	digitalWrite(clkPin, HIGH);
	delayMicroseconds(1);
	digitalWrite(clkPin, LOW);
}

/*
Sends a whole byte to the ds1868 IC

Requirements RESET PIN MUST BE HIGH;
*/
void DS1868::transmitByte(byte value) {
	byte bit;

	for (int i = 7; i >= 0; i--) {
		bit = value;
		bit &= (1 << i);
		bit >>= i;
		transmitBit(bit);
	}
}

DS1868 ds1868;
