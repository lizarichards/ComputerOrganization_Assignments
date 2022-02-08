//Question 4:
//
#include <stdio.h>

void printBytes(unsigned char *start, int len) {
	for (int i = 0; i < len; ++i) {
		printf(" %.2x", start[i]); //provides hex even when its not needed
	}
	printf("\n");
}

void printInt(int x){
	printBytes((unsigned char *) &x, sizeof(int));
}

void printFloat(float x){
	printBytes((unsigned char *) &x, sizeof(float));
}

void printShort(short x){
	printBytes((unsigned char *) &x, sizeof(short));
}

void printLong(long x){
	printBytes((unsigned char *) &x, sizeof(long));
}

void printLongLong(long long x){
	printBytes((unsigned char *) &x, sizeof(long long));
}

void printDouble(double x){
	printBytes((unsigned char *) &x, sizeof(double));
}

void main(){
	int num = 55;
	float dec = 5.5;
	short small = 55;
	long tall = 5555;
	long long taller = 55555555;
	double twice = 55;

	//most all outputs are hard to understand hex values that seem to have
	//no relation to the orignal given value

	printf("Int \n"); //prints 4 bytes worth, fills in extras with 0
	printInt(num);

	printf("Float \n"); //prints 4 bytes, fills in extras with 0
	printFloat(dec);

	printf("Short \n"); //prints 2 bytes (half of # of bytes in int), fills in extras with 0
	printShort(small);

	printf("Long \n"); //prints 8 bytes (twice of # of bytes in int), fills in extras with 0
	printLong(tall);

	printf("Long Long \n"); // prints 8 bytes (twice of # of bytes in int), fills in extras with 0
	printLongLong(taller);

	printf("Double \n");//prints 8 bytes (twice of # of bytes in int), fills in extras with 0
	printDouble(twice);
}
