#pragma once

#include <Arduino.h>
#include <Log4Ard.h>

class DS1868
{
private:
	byte trim1 = 128, trim2 = 128;
	byte rstPin, clkPin, datPin;

protected:
	void transmitByte(byte value);
	void transmitBit(byte bit);

public:
	DS1868();
	~DS1868();
	void begin(byte rstPin, byte clkPin, byte datPin);
	void setTrims();
	inline void setTrimer1Value(byte value) { trim1 = value; };
	inline void setTrimer2Value(byte value) { trim2 = value; };
};

extern DS1868 ds1868;
