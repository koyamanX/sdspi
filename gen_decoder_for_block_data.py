#!/usr/bin/env python3
for i in reversed(range(int(4096/32))):
	print('adrs == 10\'({}): {{read_data = data_block[{}:{}]; valid();}}'.format(hex(int((512-4)-i*4)), i*32+32-1, i*32))
