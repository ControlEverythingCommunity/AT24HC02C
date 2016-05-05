// Distributed with a free-will license.
// Use it any way you want, profit or free, provided it fits in the licenses of its associated works.
// AT24HC02C
// This code is designed to work with the AT24HC02C_I2CMEM I2C Mini Module available from ControlEverything.com.
// https://www.controleverything.com/content/I2C-Memory?sku=AT24HC02C_I2CMEM#tabs-0-product_tabset-2

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
	if((file = open(bus, O_RDWR)) < 0) 
	{
		printf("Failed to open the bus. \n");
		exit(1);
	}
	// Get I2C device, AT24HC02C I2C address is 0x50(80)
	ioctl(file, I2C_SLAVE, 0x50);

	// Select write address(0x0001)
	// Write the data(0x30)
	char config[2] = {0};
	config[0] = 0x0001;
	config[1] = 0x30;
	write(file, config, 2);
	sleep(1);

	// Read 1 byte of data from register(0x0001)
	// input data 
	char reg[1] = {0x0001};
	write(file, reg, 1);
	char data[1] = {0};
	if(read(file, data, 1) != 1)
	{
		printf("Erorr : Input/output Erorr \n");
		exit(1);
	}
	else
	{
		// Output data to screen
		printf("Input data : %x \n", data[0]);
	}
}