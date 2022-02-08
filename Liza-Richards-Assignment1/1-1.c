// Question 1:
//

#include <stdio.h>

void combine(unsigned int x, unsigned int y) {
	//bit 3 to 1 is from left to right
	//create two new variables for the mask of x and y
	unsigned int w;
	unsigned int z;
	//isolate bytes 3 to 1 from x using bitmask (bitwise &)
	w = x & 0b11111111111111111111111100000000;
	//isolate byte 0 from y using bitmask (bitwise &)
	z = y & 0b00000000000000000000000011111111;
	//use bitwise or to combine the two
	printf("0x%x\n", w | z);	
}

void main() {
	//tests
	combine(0x12345678, 0xABCDEF00);
	combine(0xABCDEF00, 0x12345678);
}
