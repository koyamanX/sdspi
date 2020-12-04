#ifndef SDSPI_H
#define SDSPI_H

#define HIGH 1'b1
#define LOW  1'b0
#define HI_Z 1'bz

#define R1 2'b01
#define R2 2'b10
#define R3 2'b11
#define R7 2'b11

/* m_clock at 50MHz */
declare sdspi {
	output CS;
	input MISO;
	output MOSI;
	output SCLK;

	func_in reset();
	output debug_out[8];
	output debug_status[8];
	output debug_inited;
	func_in read();
	output data[4096];
	func_out valid(data);
}

struct command_token_t {
	command[8];	
	arguments[32];
	crc[8];
};
struct response_1_t {
	start_bit[1];
	parameter_error[1];
	address_error[1];
	erase_sequence_error[1];
	communication_crc_error[1];
	illegal_command[1];
	erase_reset[1];
	in_idle_state[1];
};

#define CMD0 	0x40_00_00_00_00_95
#define CMD8 	0x48_00_00_01_aa_87
#define CMD55	0x77_00_00_00_00_01
#define ACMD41	0x69_40_ff_80_00_01
#define CMD41	ACMD41
#define CMD58	0x7a_00_00_00_00_ff
/* 512 byte */
#define CMD16	0x50_00_00_02_00_01
#define CMD17	0x51_00_00_00_00_01
#endif

