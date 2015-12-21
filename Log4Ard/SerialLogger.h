#pragma once

#include <Arduino.h>
#include <HardwareSerial.h>
#include <avr/pgmspace.h>
#include "Logger.h"

/* A Logger that outputs message to an Hardware Serial interface */
class SerialLogger :
	public Logger
{
public:
	~SerialLogger();


	void trace(const __FlashStringHelper *, ...);
	void debug(const __FlashStringHelper *, ...);
	void info(const __FlashStringHelper *, ...);
	void warning(const __FlashStringHelper *, ...);
	void error(const __FlashStringHelper *, ...);
	void critical(const __FlashStringHelper *, ...);
	
	void begin(Level);
	inline void setBaudrate(unsigned long br) { baudrate = br; }
	inline void setLogLevel(Level l){ level = l; }

	static SerialLogger& getInstance(HardwareSerial * hs, unsigned long br) { instance.setBaudrate(br); instance.setLogger(hs);  return instance; };

protected:
	void logMessage(Level l, const __FlashStringHelper * str, va_list args);
	SerialLogger();
	inline void setLogger(HardwareSerial* hs) { sLog = hs; }

private:	
	static SerialLogger instance;

	HardwareSerial * sLog;
	unsigned long baudrate;

	byte getArgsNumber(const __FlashStringHelper * str);
	char buffer[128];
};


