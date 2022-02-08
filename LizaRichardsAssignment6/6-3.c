#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float f(float *a, int n){
	float prod = 1.0f;
	for (int i = 0; i < n; ++i){
		if (a[i] != 0.0f) {
			prod *= a[i];
		}
	}
	return prod;
}

float g(float *a, int n){
	float prod = 1.0f;
	for (int i = 0; i < n; ++i){
		prod *= a[i];
	}
}

float* createArray(int size){
	float *a = (float *)malloc(size * sizeof(float));
	for (int i = 0; i < size; ++i){
		//50% chance that a[i] is 0.0f, random value on the reange
		//[0.76, 1.26] otherwise
		float r = rand()/(float)RAND_MAX;
		a[i] = r < 0.5f ? 0.0f : r + 0.26f;
	}
	return a;
}

void main(){
	int n = 10000;
	// f(a)
	float *a = createArray(n); // creates array a of size 10000
	clock_t begin = clock(); // starts clock
	f(a, n); // runs f function with array a and size of array a which is 10000
	clock_t end = clock(); // ends clock
	double time_taken = (double)(end - begin) / CLOCKS_PER_SEC; // calcs time taken
	printf("Time Taken f(a): %f\n", time_taken);
	free(a); // frees mem allocated for a

	// g(b)
	float *b = createArray(n);
	// replaces each 0.0f in array to 1.0f
	for (int i = 0; i < n; ++i){
		if (b[i] = 0.0f){
			b[i] =  1.0f;
		}
	}
	clock_t start = clock();
	g(b, n);
	clock_t finish = clock();
	double time_spent = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("Time Taken g(b): %f\n", time_spent);
	free(b);

	// g(c)
	float *c = createArray(n - 9000);
	clock_t first = clock();
	g(c, n - 9000);
	clock_t last = clock();
	double time = (double)(last - first) / CLOCKS_PER_SEC;
	printf("Time Taken g(c): %f\n", time);
	free(c);


}

//the time to run g(b) is faster than the time to run f(a). This is because the g 
//function does not have the extra if statement, so it is one less condition
//for the program to consider and therefore the g function is faster than the f function
//
//
//The time to run g(c) is faster than calling f(a) or g(b). This is because array c
//has a much smaller size than array a or b. In addition, the g function does not
//contain the extra if statement, so it has a faster run time. 
