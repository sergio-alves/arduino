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

	Serial.print(F("Pot values (0, 1) -> ("));
	Serial.print(DS1868::trim1);
	Serial.print(F(","));
	Serial.print(DS1868::trim2);
	Serial.println(F(")"));

	//stop reset
	digitalWrite(rstPin, HIGH);
	delayMicroseconds(1);

	//print message
	Serial.print(F("Pot values bits: "));
	transmitBit(0);

	transmitByte(DS1868::trim1);
	Serial.print(" ");

	transmitByte(DS1868::trim2);
	Serial.println();

	digitalWrite(rstPin, LOW);
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

	Serial.print(bit);
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