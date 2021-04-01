#pragma once
#include <iostream>
#include <string>

class Sensor
{
	private:
		uint8_t m_pin_sensor;
		uint8_t m_pin_mode;

	public:
		Sensor(uint8_t pin_sensor, uint8_t pin_mode): m_pin_sensor{pin_sensor}, m_pin_mode{pin_mode}{}

		/*
		 *	Gettery
		 */
		uint8_t get_pin_sensor(void) const { return m_pin_sensor; }
		uint8_t get_pin_mode(void) const { return m_pin_mode; }

		virtual void Set_Up();
		virtual bool Read_Digital_Pin_State();
		virtual void Print_Actual_Sensor_State();

		void Send_Actual_Sensor_State();

		~Sensor() {};
};

class PIRsensor : public Sensor
{
	private:
		bool m_detect_move_flag;

		void set_detect_move_flag(const bool& detect_move_flag) { m_detect_move_flag = detect_move_flag; };

	public:
		PIRsensor(uint8_t pin_sensor, uint8_t pin_mode): Sensor(pin_sensor, pin_mode), m_detect_move_flag{false}{}

		bool get_detect_move_flag(void) const { return m_detect_move_flag; };

		void Detect_Move(bool& actual_state);

		void Debug_PIR_Sensor(bool& actual_state, size_t& iterator);
		void Print_Actual_Sensor_State();

		~PIRsensor() {};
};