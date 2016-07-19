// Distributed with a free-will license.
// Use it any way you want, profit or free, provided it fits in the licenses of its associated works.
// PCA9536_BZ
// This code is designed to work with the PCA9536_I2CBZ I2C Mini Module available from ControlEverything.com.
// https://www.controleverything.com/content/Digital-IO?sku=PCA9536_I2CBZ#tabs-0-product_tabset-2

#include <stdio.h>
#include <stdlib.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <fcntl.h>

void main() 
{
	// Create I2C bus
	int file;
	char *bus = "/dev/i2c-1";
	if ((file = open(bus, O_RDWR)) < 0) 
	{
		printf("Failed to open the bus. \n");
		exit(1);
	}
	// Get I2C device, PCA9536_BZ I2C address is 0x41(65)
	ioctl(file, I2C_SLAVE, 0x41);

	// Select configuration register(0x03)
	// All pins configured as outputs(0xF0)
	char config[2] = {0};
	config[0] = 0x03;
	config[1] = 0xF0;
	if(write(file, config, 2) != 2)
	{
		printf("Error : Input/Output error \n");
		exit(1);
	}

	int i;
	for(i = 0; i < 4; i++)
	{
		// Select output port register(0x01)
		// Logic HIGH on each pin
		config[0]= 0x01;
		config[1]= 0xF0 | (1 << i);
		write(file, config, 2);

		if(i != 3)
		{
			printf("I/O Pin %d State is HIGH and BUZZER is OFF \n", i);
		}
		else
		{
			printf("I/O Pin %d State is HIGH and BUZZER is ON \n", i);
		}
		sleep(1);
	}
}
