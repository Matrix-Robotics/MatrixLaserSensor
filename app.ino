#include "src/MatrixLaserSensor.h"

MatrixLaser MXLaser1;
int dis;
void setup() {
  Serial.begin(115200);
  if (MXLaser1.begin()){
    Serial.println("Matirx Laser Sensor activated");
  }
  else{
    Serial.println("Matirx Laser Sensor activation failed");
  }
}

void loop() {
  Serial.println("===============================================================");

  dis = MXLaser1.getDistance();

  if(dis == 8191){
    Serial.println("TIMEOUT");
  }
  else{
    Serial.print("Distance = ");
    Serial.print(dis);
    Serial.println("mm");
  }
  delay(100);
}
