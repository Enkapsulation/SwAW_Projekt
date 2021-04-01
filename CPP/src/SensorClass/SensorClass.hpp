#pragma once
#include <iostream>
#include <string>
#include <wiringPi.h>

class Sensor
{
	public:
		Sensor() {};

		virtual void setup() = 0;
		virtual void printInfo() = 0;
		// virtual void sendStateMsg() = 0; // MQTT
		// virtual void getMsg(void* msg) = 0; // MQTT

		~Sensor() {};
};


class PIRsensor : public Sensor
{
	private:
		uint8_t m_pin_sensor;
		uint8_t m_pin_mode;
		bool m_detect_move_flag;

		void set_detect_move_flag(const bool& detect_move_flag) { m_detect_move_flag = detect_move_flag; };

	public:
		PIRsensor(uint8_t pin_sensor, uint8_t pin_mode) : m_pin_sensor{pin_sensor}, m_pin_mode{pin_mode}, m_detect_move_flag{false} { setup(); }

		void setup() override;
		void printInfo() override;

		/*
		 *	Gettery
		 */
		uint8_t get_pin_sensor(void) const { return m_pin_sensor; }
		uint8_t get_pin_mode(void) const { return m_pin_mode; }
		uint8_t get_detect_move_flag(void) const { return m_detect_move_flag; }
		bool getPinState() const { return digitalRead(m_pin_sensor); }

		bool geDetectMoveFlag(void) const { return m_detect_move_flag; };
		void sendMsgOnStateChange();
		void debugPIRSensor(bool& actual_state, size_t& iterator);
		

		~PIRsensor() {};
};