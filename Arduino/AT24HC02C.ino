// Distributed with a free-will license.
// Use it any way you want, profit or free, provided it fits in the licenses of its associated works.
// AT24HC02C
// This code is designed to work with the AT24HC02C_I2CMEM I2C Mini Module available from ControlEverything.com.
// https://www.controleverything.com/content/I2C-Memory?sku=AT24HC02C_I2CMEM#tabs-0-product_tabset-2

#include <Wire.h>

// AT24HC02C I2C address is 0x50(80)
#define Addr 0x50

void setup()
{
  // Initialise I2C communication as MASTER
  Wire.begin();
  // Initialise Serial Communication, set baud rate = 9600
  Serial.begin(9600);

  // Start I2C transmission
  Wire.beginTransmission(Addr);
  // Select write address
  Wire.write(0x0001);
  // Write the data
  Wire.write(0x30);
  // Stop I2C transmission
  Wire.endTransmission();
  delay(300);
}

void loop()
{
  unsigned int data = 0;
  
  // Start I2C transmission
  Wire.beginTransmission(Addr);
  // Select data register
  Wire.write(0x0001);
  // Stop I2C transmission
  Wire.endTransmission();

  // Request 1 byte of data
  Wire.requestFrom(Addr, 1);

  // Read 1 byte of data
  if (Wire.available() == 1)
  {
    data = Wire.read();
  }

  // Output data to serial monitor
  Serial.print("Input data : ");
  Serial.println(data);
  delay(500);
}


