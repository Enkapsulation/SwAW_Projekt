// delete iostream after coorect implementation of Send_Actual_Sensor_State
#include <iostream>
#include "SensorClass.hpp"
#include <wiringPi.h>

/*============================================================================*\
* PIRSensor class method
\*============================================================================*/
void PIRsensor::setup()
{
	pinMode(m_pin_sensor, m_pin_mode);
}

void PIRsensor::printInfo()
{
	std::cout << "[STATE]: \n\tPin number: " << get_pin_sensor() << "\n\tPin mode: " << get_pin_mode() << "\n\tDetect flag: " << m_detect_move_flag << std::endl;
}

void PIRsensor::sendMsgOnStateChange()
{
	bool actual_state = getPinState();

	if((actual_state) && (!m_detect_move_flag))
	{
		set_detect_move_flag(true);
		// sendStateMsg();
	}
	else if((!actual_state) && (m_detect_move_flag))
	{
		set_detect_move_flag(false);
	}
}

void PIRsensor::debugPIRSensor(bool& actual_state, size_t& iterator)
{
	while (1)
	{
		iterator = 0;
		actual_state = getPinState();
		
		if(actual_state)
		{
			while (getPinState())
			{
				iterator++;
			}

			std::cout << "[STAN] 1: " << iterator << std::endl;
		}
		else
		{
			while (!(getPinState()))
			{
				iterator++;
			}
			
			std::cout << "[STAN] 0: " << iterator << std::endl;
		}
	}
}

