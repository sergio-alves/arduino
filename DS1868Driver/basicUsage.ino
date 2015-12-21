#include <DS1868.h>

#define RESET_PIN						9
#define CLOCK_PIN						8
#define DATA_PIN						7

void setup() {
	/* Begin DS1868 driver module */
	ds1868.begin(RESET_PIN, CLOCK_PIN, DATA_PIN);
}

void loop() {
	String str;
	int value;
	char buffer[10];

	while (Serial.available() > 0) {
		str = Serial.readString();
		str.toCharArray(buffer, 10, 0);

		if (sscanf(buffer, "SET_P1 %i", &value) == 1) {
			if (value > 0 && value < 256) {
				Serial.print("Setting POT 1 with value : ");
				Serial.println(value);

				ds1868.setTrimer1Value(value);
				ds1868.setTrims();
			}
			else{
				Serial.println("Value must be between 0 and 255");
			}
		}

		if (sscanf(buffer, "SET_P2 %i", &value) == 1) {
			if (value > 0 && value < 256) {
				Serial.print("Setting POT 2 with value : ");
				Serial.println(value);

				ds1868.setTrimer1Value(value);
				ds1868.setTrims();
			} else{
				Serial.println("Value must be between 0 and 255");
			}
		}
	}
}