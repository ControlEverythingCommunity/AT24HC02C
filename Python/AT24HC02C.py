# Distributed with a free-will license.
# Use it any way you want, profit or free, provided it fits in the licenses of its associated works.
# AT24HC02C
# This code is designed to work with the AT24HC02C_I2CMEM I2C Mini Module available from ControlEverything.com.
# https://www.controleverything.com/content/I2C-Memory?sku=AT24HC02C_I2CMEM#tabs-0-product_tabset-2

import time
import smbus

# Get I2C bus
bus = smbus.SMBus(1)

# AT24HC02C address, 0x50(80)
# Select write address
#		0x0001(01)
# Select write data
#		0x30(48)
bus.write_i2c_block_data(0x50, 0x00, [0x01 , 0x30])

time.sleep(0.5)

# AT24HC02C address, 0x50(80)
# Select read address
bus.write_i2c_block_data(0x50, 0x00, [0x01])
time.sleep(0.5)

# AT24HC02C address, 0x50(80)
# Read data back
data = bus.read_byte(0x50)

# Output data to screen
print "Input Data : ",data
