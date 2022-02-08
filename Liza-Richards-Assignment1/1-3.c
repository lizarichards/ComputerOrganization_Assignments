//Question 3:
//

#include <stdio.h>

void oddBit(unsigned int x){
	//bitmask to isolate the odd bits
	unsigned int w = x & 0b10101010101010101010101010101010;
	//double logical not, makes sure that it is not the opposite of w, not w means there are evens, not not w are the odds
	printf("%x\n", !(!w)); 
}

void main(){
	oddBit(0x1); //should be 0
	oddBit(0x2); //should be 1
	oddBit(0x3); //should be 1
	oddBit(0x4); //should be 0
	oddBit(0xFFFFFFFF); //should be 1
	oddBit(0xAAAAAAAA); //should be 1
	oddBit(0x55555555); //should be 0

}
