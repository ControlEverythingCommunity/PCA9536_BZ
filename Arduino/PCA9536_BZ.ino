// Distributed with a free-will license.
// Use it any way you want, profit or free, provided it fits in the licenses of its associated works.
// PCA9536_BZ
// This code is designed to work with the PCA9536_I2CBZ I2C Mini Module available from ControlEverything.com.
// https://www.controleverything.com/content/Digital-IO?sku=PCA9536_I2CBZ#tabs-0-product_tabset-2

#include <Wire.h>

// PCA9536 I2C address is 0x41(65)
#define Addr 0x41

void setup()
{
  // Initialise I2C communication as Master
  Wire.begin();
  // Initialise serial communication, set baud rate = 9600
  Serial.begin(9600);

  // Start I2C transmission
  Wire.beginTransmission(Addr);
  // Select configuration register
  Wire.write(0x03);
  // Select GPIO as output
  Wire.write(0xF0);
  // Stop I2C transmission
  Wire.endTransmission();
  delay(300);
}

void loop()
{
  for (int i = 0; i < 4; i++)
  {
    // Start I2C transmission
    Wire.beginTransmission(Addr);
    // Select output port register
    Wire.write(0x01);
    // Logic HIGH on each pin
    Wire.write(0xF0 | (1 << i));
    // Stop I2C transmission
    Wire.endTransmission();

    if ( i != 3)
    {
      Serial.print("I/O Pin ");
      Serial.print(i);
      Serial.println(" State is HIGH and Buzzer is OFF");
    }
    else
    {
      Serial.print("I/O Pin ");
      Serial.print(i);
      Serial.println(" State is HIGH and Buzzer is ON");
    }
    delay(1000);
  }
}
