#ifndef SDSPI_SLAVE_H
#define SDSPI_SLAVE_H

#define HIGH 1'b1
#define LOW  1'b0
#define HI_Z 1'bz

declare sdspi_slave {
	input CS;
	input MOSI;
	output MISO;
	input SCLK;
	output adrs[32];
	input read_block_data[4096];
	func_in block_data_valid();
	func_out read(adrs);
}
#endif
