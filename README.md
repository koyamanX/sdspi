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

### References
[Part1 physical layer simplified specification Ver8.00](Part1_Physical_Layer_Simplified_Specification_Ver8.00.pdf)  
[1](http://elm-chan.org/docs/mmc/mmc.html)  
[2](http://memes.sakura.ne.jp/memes/?page_id=2124)  
[3](https://userweb.alles.or.jp/chunichidenko/sdif27.html)  
[4](http://yoshi-s.cocolog-nifty.com/cpu/2018/09/bus-piratesd-01.html)  
[5](https://bluefish.orz.hm/sdoc/psoc_mmc.html)  
[6](http://memes.sakura.ne.jp/memes/?page_id=2225)  
[7](http://www.rjhcoding.com/avrc-sd-interface-4.php)  
[8](http://www.robotsfx.com/robot/robohow/RoboHow91/RoboHow91.html)  
[9](https://userweb.alles.or.jp/chunichidenko/sdif28.html)  
