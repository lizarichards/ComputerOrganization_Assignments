// Question 2:
//

#include <stdio.h>

void extract(unsigned int x, int i){

	// shifts x over to get the targeted bits
	int w = x << (24 - (i << 3)); 
	// arithmetic right shift fills in empty spots with most significant bit
	int z = w >> 24;
	printf("0x%x\n", z);

}

void main(){
	extract(0x12345678, 0); // should be 0x00000078
	extract(0xABCDEF00, 2); //should be 0xFFFFFFCD
}
