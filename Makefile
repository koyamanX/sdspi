NSL2VL=nsl2vl
NFLAGS=-O2 -neg_res -verisim2 -target sdspi_sim
IVERILOG=iverilog

sdspi_sim: sdspi_sim.nsl
	$(NSL2VL) $(NFLAGS) $< -o $@.v
	$(IVERILOG) $@.v -o $@

clean:
	@rm -rf *.v sdspi_sim *.vcd
