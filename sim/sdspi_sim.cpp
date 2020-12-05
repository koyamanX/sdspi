#include <verilated.h>
#include "verilated_vcd_c.h"
#include "Vsdspi_sim.h"
#include <string.h>
#include <stdio.h>

using namespace std;

int main(int argc, char **argv) {
	Vsdspi_sim *sdspi_sim_env;
	VerilatedVcdC *tfp;
	Verilated::commandArgs(argc, argv);
	Verilated::traceEverOn(true);
	uint64_t cnt = 0;
	FILE *fp;
	uint8_t buf[512];
	size_t len;

	sdspi_sim_env = new Vsdspi_sim;
	tfp = new VerilatedVcdC;
	sdspi_sim_env->trace(tfp, 99);
	tfp->open("sdspi_sim.vcd");
	fp = fopen("img.iso", "rb");
	
	sdspi_sim_env->m_clock = 0;
	sdspi_sim_env->p_reset = 0;
	sdspi_sim_env->eval();
	sdspi_sim_env->m_clock = 1;
	sdspi_sim_env->p_reset = 0;
	sdspi_sim_env->eval();
	sdspi_sim_env->m_clock = 0;
	sdspi_sim_env->p_reset = 0;
	sdspi_sim_env->eval();
	sdspi_sim_env->m_clock = 1;
	sdspi_sim_env->p_reset = 0;
	sdspi_sim_env->eval();

	while(!Verilated::gotFinish()) {
		sdspi_sim_env->m_clock = !sdspi_sim_env->m_clock;
		sdspi_sim_env->p_reset = 1;
		sdspi_sim_env->eval();
		if(sdspi_sim_env->read_block) {
			fseek(fp, sdspi_sim_env->adrs*512, SEEK_SET);
			len = fread(buf, sizeof(uint8_t), 512, fp);
			memcpy(sdspi_sim_env->block_data, buf, 512);
			sdspi_sim_env->block_data_valid = 1;
		} else {
			sdspi_sim_env->block_data_valid = 0;
		}
		sdspi_sim_env->eval();
		tfp->dump(cnt);
		if(cnt == 0x4fffff) {
			break;
		}
		cnt++;
	}
	for(int i = 0; i < 512; i++)
		printf("%x:%x\n", i, buf[i]);
	tfp->close();
	sdspi_sim_env->final();
	fclose(fp);
}
