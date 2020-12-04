NSL2VL=nsl2vl
NFLAGS=-O2 -neg_res 
IVERILOG=iverilog

sdspi_sim: sdspi_sim.cpp obj_dir sdspi_sim.v
	cd obj_dir && make -f Vsdspi_sim.mk Vsdspi_sim
	cp obj_dir/Vsdspi_sim ./$@
sdspi_sim.v: sdspi_sim.nsl
	$(NSL2VL) $(NFLAGS) $< -o $@
obj_dir: sdspi_sim.cpp sdspi_sim.v
	verilator --cc -Wno-lint -Wno-UNOPTFLAT --trace --trace-underscore sdspi_sim.v --top-module sdspi_sim --exe sdspi_sim.cpp -O3 --autoflush -CFLAGS "-O2 -static"
clean:
	@rm -rf *.v sdspi_sim *.vcd obj_dir
