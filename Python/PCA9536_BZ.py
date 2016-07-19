# Distributed with a free-will license.
# Use it any way you want, profit or free, provided it fits in the licenses of its associated works.
# PCA9536_BZ
# This code is designed to work with the PCA9536_I2CBZ I2C Mini Module available from ControlEverything.com.
# https://www.controleverything.com/content/Digital-IO?sku=PCA9536_I2CBZ#tabs-0-product_tabset-2

import smbus
import time

# Get I2C bus
bus = smbus.SMBus(1)

# PCA9536 address, 0x41(65)
# Select configuration register, 0x03(03)
#		0xF0(240)	All pins configured as inputs
bus.write_byte_data(0x41, 0x03, 0xF0)

for i in range(0, 4) :
	# PCA9536 address, 0x41(65)
	# Select output register, 0x01(01)
	#		Logic HIGH on each pin
	bus.write_byte_data(0x41, 0x01, (0xF0 | (1 << i)))
	
	if i != 3:
		print "I/O Pin %d State is HIGH and BUZZER is OFF %n " %i
	else :
		print "I/O Pin %d State is HIGH and BUZZER is ON %n " %i
	time.sleep(1)
