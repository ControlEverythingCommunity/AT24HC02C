// Distributed with a free-will license.
// Use it any way you want, profit or free, provided it fits in the licenses of its associated works.
// A13XX
// This code is designed to work with the ADC121C_A13XX_I2CS_A1304ELHLX-05-T I2C Mini Module available from ControlEverything.com.
// https://www.controleverything.com/content/Hall-Effect?sku=ADC121C_A13XX_I2CS_A1304ELHLX-05-T#tabs-0-product_tabset-2

import com.pi4j.io.i2c.I2CBus;
import com.pi4j.io.i2c.I2CDevice;
import com.pi4j.io.i2c.I2CFactory;
import java.io.IOException;

public class A13xx
{
	public static void main(String args[]) throws Exception
	{
		// Create I2C bus
		I2CBus Bus = I2CFactory.getInstance(I2CBus.BUS_1);
		// Get I2C device, A13XX I2C address is 0x50(80)
		I2CDevice device = Bus.getDevice(0x50);
		Thread.sleep(500);

		// Read 2 bytes of data
		// raw_adc msb, raw_adc lsb
		byte[] data = new byte[2];
		device.read(data , 0, 2);

		// Convert the data to 12-bits
		int raw_adc = ((data[0] & 0x0F) * 256 + (data[1] & 0xFF));
		double angle = (raw_adc / 4096.0) * 360;

		// Output data to screen
		System.out.printf("Magnetic Angle : %.2f %n", angle);
	}
}
