#ifndef _MatrixLaserSensor_H_
#define _MatrixLaserSensor_H_

#include <Arduino.h>
#include <Wire.h>

#ifndef ADDR_PCA954X
#define ADDR_PCA954X 0x70
#endif

#define MatrixLaser_ADDR 0x26

class MatrixLaser{
	private:
	typedef enum __LaserRegType
	{
		Device_ID = 1,
		Device_CONFIG,
		Distance_H,
		Distance_L
	} LaserRegType;
	
	uint8_t _ch=0, _ver=1;
	uint8_t i2cReadData(LaserRegType reg);
	void i2cMUXSelect();
	void i2cWriteData(LaserRegType reg, uint8_t data);
public:
	friend class MiniI2C;
	bool begin();
	uint16_t getDistance();
};

#endif
