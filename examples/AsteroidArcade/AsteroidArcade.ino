/*
* AsteroidAttack
*/

#include <CircuitsFunProjects.h>

float x, y, z;
Button button(3);
int buttonState;

void setup() {
  Serial.begin(9600);
  IMU.begin();
  button.begin();
  Serial.println("0,0,0");
}

void loop() {
  // read raw gyro measurements from device
  if (IMU.accelerationAvailable()) {
    IMU.readAcceleration(x, y, z);
  }
  int roll = y*100;
  buttonState = button.isPressed(); 
  // when Serial is open, send a "s" to processing
  if (Serial.available() > 0) {
    int val = Serial.read();
    if (val == 's') { // if incoming serial is "s"
      Serial.print(roll); Serial.print(",");
      Serial.print(buttonState);  Serial.print(",");
      Serial.println("");
    }
  }
  delay(30);
}
