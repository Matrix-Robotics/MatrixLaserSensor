#include "MatrixLaserSensor.h"

bool MatrixLaser::begin(){
	Wire.begin();
	i2cMUXSelect();
	delay(50);
	if(i2cReadData(Device_ID) == 0x47){
		i2cWriteData(Device_CONFIG, 0x04); // reset
		delay(500);
		i2cWriteData(Device_CONFIG, 0x02); // enable
		return true;
	}
	else{
		return false;
	}	
}

int MatrixLaser::getDistance() {
    i2cMUXSelect();
    if (((i2cReadData(Device_CONFIG) & 0x01) == 0)) {
        int data = (int)(i2cReadData(Distance_H) << 8 | i2cReadData(Distance_L));  // 改為 int 型別
        return data;
    } else {
        return 8191;
    }
}

uint8_t MatrixLaser::i2cReadData(LaserRegType reg){
	
	Wire.beginTransmission(MatrixLaser_ADDR);
	Wire.write(reg);
	Wire.endTransmission(1);

	delay(1);

	Wire.requestFrom(MatrixLaser_ADDR, 1);

	delay(1);

	return Wire.read();
}

void MatrixLaser::i2cMUXSelect(){
	switch (_ver)
	{
	case 2:
		Wire.beginTransmission(ADDR_PCA954X);
		Wire.write(_ch + 4);
		Wire.endTransmission(1);

		delayMicroseconds(300);
		break;
	case 3:
		Wire.beginTransmission(ADDR_PCA954X);
		Wire.write((1 << _ch));
		Wire.endTransmission(1);
		
		delayMicroseconds(300);
		break;
	default:
		break;
	}
}

void MatrixLaser::i2cWriteData(LaserRegType reg, uint8_t data){

	Wire.beginTransmission(MatrixLaser_ADDR);

	Wire.write(reg);
	Wire.write(data);

	Wire.endTransmission(1);
}
