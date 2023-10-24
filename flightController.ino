#include "PluggableUSBHID.h"
#include "USBMouse.h"
#include <Arduino_LSM9DS1.h>

USBMouse Mouse;

void setup() {
  if (!IMU.begin()) {
    while (1);
  }

}

void loop() {
  // Read accelerometer data from LSM9DS1
  float accX, accY, accZ;
  IMU.readAcceleration(accX, accY, accZ);

  // Scale and map the accelerometer data to control mouse movements
  int16_t deltaX = map(accX * 1000, -2000, 2000, -10, 10); // Adjust the mapping values as needed
  int16_t deltaY = map(accY * 1000, -2000, 2000, -10, 10);

  // Move the mouse based on accelerometer data
  Mouse.move(deltaX, deltaY);

  delay(20); // Adjust the delay as needed
}


// Ble Mosue Ends Here
