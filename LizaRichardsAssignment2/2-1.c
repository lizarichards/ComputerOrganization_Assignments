// Question 1:
//

#include <stdio.h>

void mask(int n){
	// use subtraction
	// shift 1 over n bits to get to the n lowest bits
	// subtracing one (could also invert using ~) clears the set bit
	// and instead sets the least significant bits (gets the mask)
	unsigned int x = (1 << n) - 1;
	printf("0x%x\n", x);
}

void main(){
	mask(1);
	mask(2);
	mask(3);
	mask(5);
	mask(8);
	mask(16);
	mask(31);
}
