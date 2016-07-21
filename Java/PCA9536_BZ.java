// Distributed with a free-will license.
// Use it any way you want, profit or free, provided it fits in the licenses of its associated works.
// PCA9536_BZ
// This code is designed to work with the PCA9536_I2CBZ I2C Mini Module available from ControlEverything.com.
// https://www.controleverything.com/content/Digital-IO?sku=PCA9536_I2CBZ#tabs-0-product_tabset-2

import com.pi4j.io.i2c.I2CBus;
import com.pi4j.io.i2c.I2CDevice;
import com.pi4j.io.i2c.I2CFactory;
import java.io.IOException;

public class PCA9536_BZ
{
	public static void main(String args[]) throws Exception
	{
		// Create I2C bus
		I2CBus Bus = I2CFactory.getInstance(I2CBus.BUS_1);
		// Get I2C device, PCA9536_BZ I2C address is 0x41(65)
		I2CDevice device = Bus.getDevice(0x41);

		// Select configuration register
		// All pins configured as outputs
		device.write(0x03, (byte)0xF0);

		for(int i = 0; i < 4; i++)
		{
			// Select output port register
			// Logic HIGH on each pin
			device.write(0x01, (byte)(0xF0 | (1 << i)));
			
			if(i != 3)
			{
				System.out.printf("I/O Pin %d State is HIGH and BUZZER is OFF %n ", i);
			}
			else
			{
				System.out.printf("I/O Pin %d State is HIGH and BUZZER is ON %n ", i);
			}
			Thread.sleep(1000);
		}
	}
}
