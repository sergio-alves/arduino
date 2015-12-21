#include "SerialLogger.h"

SerialLogger SerialLogger::instance = SerialLogger();

/* Constructor for the SerialLogger. Set the Hardware logger to get data out. */
SerialLogger::SerialLogger() {}

SerialLogger::~SerialLogger(){
	//nothing to free since no new instanciation
}

/**
 * To be called in setup() main function
 */
void SerialLogger::begin(Level l){
	level = l;
	sLog->begin(baudrate);
}

/* Log a trace message using a string stored into program space and a variable list of arguments like with printf.*/
void SerialLogger::trace(const __FlashStringHelper * str, ...){
	va_list argp;
	va_start(argp, getArgsNumber(str));
	logMessage(TRACE, str, argp);
	va_end(argp);
}

/* Log a debug message using a string stored into program space and a variable list of arguments like with printf.*/
void SerialLogger::debug(const __FlashStringHelper * str, ...){
	va_list argp;
	va_start(argp, getArgsNumber(str));
	logMessage(DEBUG, str, argp);
	va_end(argp);
}

/* Log an info message using a string stored into program space and a variable list of arguments like with printf.*/
void SerialLogger::info(const __FlashStringHelper * str, ...){
	va_list argp;
	va_start(argp, getArgsNumber(str));
	logMessage(INFO, str, argp);
	va_end(argp);
}

/* Log a warning message using a string stored into program space and a variable list of arguments like with printf.*/
void SerialLogger::warning(const __FlashStringHelper * str, ...){
	va_list argp;
	va_start(argp, getArgsNumber(str));
	logMessage(WARNING, str, argp);
	va_end(argp);
}

/* Log an error message using a string stored into program space and a variable list of arguments like with printf.*/
void SerialLogger::error(const __FlashStringHelper * str, ...){
	va_list argp;
	va_start(argp, getArgsNumber(str));
	logMessage(ERROR, str, argp);
	va_end(argp);
}

/* Log a critical message using a string stored into program space and a variable list of arguments like with printf.*/
void SerialLogger::critical(const __FlashStringHelper * str, ...){
	va_list argp;
	va_start(argp, getArgsNumber(str));
	logMessage(CRITICAL, str, argp);
	va_end(argp);
}

/* Gets the number of arguments requested in string stored into program space */
byte SerialLogger::getArgsNumber(const __FlashStringHelper * str) {
	const PROGMEM char *ptr = (const PROGMEM char *)str;
	int count = 0;
	char c;

	do {
		c = pgm_read_byte(ptr++);
		if (c == '%') {
			c = pgm_read_byte(ptr);

			if (c != '%') {
				count++;
			}
		}
	} while (c != 0);

	return count;
}

/* Log a message stored into program space or not depending on the message level */
void SerialLogger::logMessage(Level l, const __FlashStringHelper * str, va_list args) {
	if (sLog != NULL && l >= level){
		vsprintf_P(buffer, (const char *)str, args);
		sLog->println(buffer);
		sLog->flush();
	}
}
