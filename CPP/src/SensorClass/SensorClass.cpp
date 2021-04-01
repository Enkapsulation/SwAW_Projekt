// delete iostream after coorect implementation of Send_Actual_Sensor_State
#include <iostream>
#include "SensorClass.hpp"
#include <wiringPi.h>

/*============================================================================*\
* Sensor class method
\*============================================================================*/
void Sensor::Set_Up()
{
	pinMode(m_pin_sensor, m_pin_mode);
}

bool Sensor::Read_Digital_Pin_State()
{
	return (bool)digitalRead(m_pin_sensor);
}

void Sensor::Print_Actual_Sensor_State()
{
	std::cout << "[STATE]: \n\tPin number: " << this->m_pin_sensor << "\n\tPin mode: " << this->m_pin_mode << std::endl;
}

void Sensor::Send_Actual_Sensor_State()
{
	std::cout << "[SEND] Sensor State to MQTT" << std::endl;
}


/*============================================================================*\
* PIRSensor class method
\*============================================================================*/
void PIRsensor::Detect_Move(bool& actual_state)
{
	actual_state = this->Read_Digital_Pin_State();

	if((actual_state) && (!m_detect_move_flag))
	{
		this->set_detect_move_flag(true);
		this->Send_Actual_Sensor_State();
	}
	else if((!actual_state) && (m_detect_move_flag))
	{
		this->set_detect_move_flag(false);
	}
}

void PIRsensor::Debug_PIR_Sensor(bool& actual_state, size_t& iterator)
{
	while (1)
	{
		iterator = 0;
		actual_state = this->Read_Digital_Pin_State();
		
		if(actual_state)
		{
			while (this->Read_Digital_Pin_State())
			{
				iterator += 1;
			}

			std::cout << "[STAN] 1: " << iterator << std::endl;
		}
		else
		{
			while (!(this->Read_Digital_Pin_State()))
			{
				iterator += 1;
			}
			
			std::cout << "[STAN] 0: " << iterator << std::endl;
			
		}
	}
}

void PIRsensor::Print_Actual_Sensor_State()
{
	std::cout << "[STATE]: \n\tPin number: " << get_pin_sensor() << "\n\tPin mode: " << get_pin_mode() << "\n\tDetect flag: " << this->m_detect_move_flag << std::endl;
}
