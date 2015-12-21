#include <Arduino.h>
#include <avr/pgmspace.h>
#include <Log4Ard.h>

Logger& logger = SerialLogger::getInstance(&Serial, 115200);

// the setup function runs once when you press reset or power the board
void setup() {
	logger.begin(WARNING);
}

// the loop function runs over and over again until power down or reset
void loop() {
	logger.trace(F("Message trace %i, %d, %X, %lu"), 8, 12, 713, 32002LU);
	logger.debug(F("Message debug %i, %d, %X, %lu"), 8, 12, 713, 32002LU);
	logger.info(F("Message info %i, %d, %X, %lu"), 8, 12, 713, 32002LU);
	logger.warning(F("Message warning %i, %d, %X, %lu"), 8, 12, 713, 32002LU);
	logger.error(F("Message error %i, %d, %X, %lu"), 8, 12, 713, 32002LU);
	logger.critical(F("Message critical %i, %d, %X, %lu"), 8, 12, 713, 32002LU);
	delay(1000);
}

