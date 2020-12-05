## logic implemented in NSL for accessing SDHC compatible card on FPGA.

### Description
- Controller for SDHC compatible card written in NSL for FPGA.
- We assume that m\_clock is connected to 50MHz clock.
- Internal clock generator generates 100KHz for initialization and 25MHz for operation after entering idle state.

### Simulation
We can test this module by invoking `make sim` in `sim` directory, then `sdspi_sim` executable are generated.  
This sample simulation simulate single block read to virtual disk(img.iso, behaviour is simulated in sdspi\_slave.nsl and data is provided from sdspi\_sim.cpp).  
We can confirm that boot signature is correctly acquired.  
### FPGA

