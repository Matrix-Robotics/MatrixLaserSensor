#include <MatrixLaserSensor.h>

MatrixLaser MXLaser1;

void setup() {
  Serial.begin(115200);
  if (MXLaser1.begin()){
    Serial.println("Matirx Laser Sensor activated");
  }
  else{
    Serial.println("Matirx Laser Sensor activation failed");
  }

  MXLaser1.setSR(63);
  Serial.println("Set fill-light open and in auto adjust mode");
}

void loop() {
  Serial.println("===============================================================");
  Serial.print("R=");
  Serial.println(MXLaser1.getDistance());
  delay(200);
}
