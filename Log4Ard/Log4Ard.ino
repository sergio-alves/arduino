/*
 Name:		Log4Ard.ino
 Created:	12/20/2015 12:11:26 PM
 Author:	Sergio
*/
#include "Log4Ard.h"

Logger& logger = SerialLogger::getInstance(&Serial, 115200);

// the setup function runs once when you press reset or power the board
void setup() {
	logger.begin(WARNING);
}

// the loop function runs over and over again until power down or reset
void loop() {
//	logger.info(F("Message info : %i, %d, %X, %lu"), 5,6,713,32001LU);
	logger.critical(F("Message critical %i, %d, %X, %lu"), 8, 12, 713, 32002LU);
	delay(1000);
}
