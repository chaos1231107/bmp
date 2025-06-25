#include <Wire.h>
#include <SPI.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>

#define SCL 8
#define SDA 9
#define CSB 10
#define SDO 11

Adafruit_BMP280 bmp(CSB, SDA, SDO, SCL);
float init_altitude = 0.0f;
bool isCalibrated = false;

void setup() {
  Serial.begin(9600);

  if (!bmp.begin()) {
    Serial.println("SPI Connection Failed!");
    while(1);
  }

}

void loop() {
  float altitude = bmp.readAltitude(1013.25);
  if (!isCalibrated) {
    init_altitude = altitude;
    isCalibrated = true;
  }
  float cali_altitude = altitude - init_altitude;
  Serial.println(cali_altitude);
  delay(1000);
}
