#include <stdio.h>

int f(int a, int b, int c, int d, int n){
	int result = 0;
	int ab = a * b;
	int cd = c * d;
	int value = ab;
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < n; ++j){
			result += value + j;
		}
		value += cd; // adds cd with each incrementation of i instead of  i*c*d
	}

	printf("%d\n", result);	
	return result;
}

void main(){
	f(1, 2, 3, 4, 5); // 700
	f(2, 3, 4, 5, 6); // 2106
	f(6, 5, 4, 3, 2); // 146
	f(5, 4, 3, 2, 1); // 20
}
