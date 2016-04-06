# Distributed with a free-will license.
# Use it any way you want, profit or free, provided it fits in the licenses of its associated works.
# A13XX
# This code is designed to work with the ADC121C_A13XX_I2CS_A1304ELHLX-05-T I2C Mini Module available from ControlEverything.com.
# https://www.controleverything.com/content/Hall-Effect?sku=ADC121C_A13XX_I2CS_A1304ELHLX-05-T#tabs-0-product_tabset-2

import smbus
import time

# Get I2C bus
bus = smbus.SMBus(1)

# A13XX address, 0x50(80)
# Read data back from 0x00(00), 2 bytes
# raw_adc MSB, raw_adc LSB
data = bus.read_i2c_block_data(0x50, 0x00, 2)

# Convert the data to 12-bits
raw_adc = ((data[0] & 0x0F) * 256.0) + data[1]
angle = (raw_adc / 4096.0) * 360.0

# Output data to screen
print "Magnetic Angle : %.2f " %angle
