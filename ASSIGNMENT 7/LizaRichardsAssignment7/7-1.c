#include <stdio.h>

unsigned int getOffset(unsigned int address){
	unsigned int x;
	x = address & 0xFF; // isolates last two bytes using mask
	printf("offset: %x\n", x);
}

unsigned int getSet(unsigned int address){
	unsigned int x;
	unsigned int y;
	x = address & 0x00000F00; // isolates fifth byte using mask
	y = x >> 8; // gets rid of remaining zeroes
	printf("set: %x\n", y);
}

unsigned int getTag(unsigned int address){
	unsigned int x;
	unsigned int y;
	x = address & 0xFFFFF000; // isolates bytes 0-4 using mask
	y = x >> 12; // gets rid of remaining zeroes
	printf("tag: %x\n", y);
}

void main(){
	getOffset(0x12345678); // 78
	getOffset(0x87654321); // 21
	getTag(0x12345678); // 12345
	getTag(0x87654321); // 87654
	getSet(0x12345678); // 6
	getSet(0x87654321); // 3
}
