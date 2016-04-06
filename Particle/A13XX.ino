// Distributed with a free-will license.
// Use it any way you want, profit or free, provided it fits in the licenses of its associated works.
// A13XX
// This code is designed to work with the ADC121C_A13XX_I2CS_A1304ELHLX-05-T I2C Mini Module available from ControlEverything.com.
// https://www.controleverything.com/content/Hall-Effect?sku=ADC121C_A13XX_I2CS_A1304ELHLX-05-T#tabs-0-product_tabset-2

#include <application.h>
#include <spark_wiring_i2c.h>

// A13XX I2C address is 0x50(80)
#define Addr 0x50

int raw_adc = 0;
float angle = 0;

void setup()
{
  // Set variable
  Particle.variable("i2cdevice", "A13XX");
  Particle.variable("angle", angle);

  // Initialise I2C communication as Master
  Wire.begin();
  // Initialise serial communication, set baud rate = 9600
  Serial.begin(9600);
  delay(300);
}

void loop()
{
  unsigned int data[2];

  // Start I2C Transmission
  Wire.beginTransmission(Addr);
  // Stop I2C Transmission
  Wire.endTransmission();

  // Request 2 byte of data
  Wire.requestFrom(Addr, 2);

  // Read 2 bytes of data
  // raw_adc msb, raw_adc lsb
  if (Wire.available() == 2)
  {
    data[0] = Wire.read();
    data[1] = Wire.read();
  }

  // Convert the data to 12-bits
  raw_adc = ((data[0] & 0x0F) * 256) + (data[1] & 0xFF);
  angle = (raw_adc * 360.0) / 4096.0;

  // Output data to dashboard
  Particle.publish("Magnetic Angle :", String(angle));
  delay(500);
}

