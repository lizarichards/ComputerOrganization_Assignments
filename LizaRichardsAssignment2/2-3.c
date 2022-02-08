// Question 3:
//

#include <stdio.h>

int le(float x, float y){
	unsigned int ux = *((unsigned int*) &x);
	unsigned int uy = *((unsigned int*) &y);
	unsigned int sx = ux >> 31; // extract sign bit of ux
	unsigned int sy = uy >> 31; // extract sign but of uy
	ux <<= 1; // drop sign bit of ux
	uy <<= 1; //drop sign bit of uy
	// TO DO: return using sx, sy, ux, uy

	// want to show x <= y
	// sx and sy are the sign bits 0 = pos and 1 = neg
	//if ux and uy are zero, its true
	unsigned int num = (ux == 0 && uy == 0);

	// if sx and sy are negative, then ux is greater than uy is true
	// if sx and sy are positive, then uy is greater than ux is true
	// wherever sx > sy (sign bits) is true
	unsigned int neg = ((sx == 1) && (sy == 1) && (ux >= uy));
	unsigned int pos = ((sx == 0) && (sy == 0) && (ux <= uy));	
	int result = (num || neg || pos || (sx > sy));
	//or together all the cases that are true to combine the results

	printf("%d\n", result);
	return result;

}

void main(){
	le(0.0f, 0.0f); //should be 1
	le(-0.0f, 0.0f); //should be 1
	le(-1.0f, -1.0f); //should be 1
	le(1.0f, 1.0f); //should be 1
	le(-1.0f, 0.0f); //should be 1
	le(0.0f, 1.0f); //should be 1
	le(1.0f, 0.0f); //should be 0
	le(0.0f, -1.0f); //should be 0
	le(-1.0f, -2.0f); //should be 0
}
