// Question 2:
//

#include <stdio.h>

void replace(unsigned int x, int i, unsigned char b) {
	unsigned int w;
	unsigned int z;
	unsigned int y;
	w = i << 3; // i shifts to align for input byte
	z = 0xFF << w; //masks the bits that will be replaced with b and replace rest with 0
	y = (z & x) ^ x; // mask to get first two bits and then exlusive or swaps mask bits and  original bits, gets rid of bit to be swapped

	printf("0x%x\n", y | (b << w)); //moves b to the byte location
	//bitwise or combines y and b

}

void main(){
	replace(0x12345678, 3, 0xAB); //result should be 0xAB345678
	replace(0x12345678, 0, 0xAB); //result should be 0x123456AB
}
