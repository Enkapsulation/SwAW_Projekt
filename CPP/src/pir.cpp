#include <iostream>
#include <wiringPi.h>
#include "SensorClass/SensorClass.hpp"

/* Take a look on gpio readall */
#define PIR_PIN 7

int main()
{
	wiringPiSetup();
	PIRsensor PIR_sensor(PIR_PIN, INPUT);
	size_t iterator { 0 };
	uint8_t actual_state { 0 };

	#if defined (_DEBUG_FLAG)
	PIR_sensor.Debug_PIR_Sensor(actual_state, iterator);
	#endif /* _DEBUG_FLAG  */

	PIR_sensor.Print_Actual_Sensor_State();

	// PIR_sensor.Detect_Move(actual_state);
}
