#include <stdio.h>
#include <time.h>

void inner1(float *u, float *v, int length, float *dest){
	int i;
	float sum = 0.0f;

	for (i = 0; i < length; ++i){
		sum += u[i] * v[i];
	}
	*dest = sum;
}

void inner2(float *u, float *v, int length, float *dest){
	int i;
	// allows parallel accumulation
	float sum1 = 0.0f;
	float sum2 = 0.0f;
	float sum3 = 0.0f;
	float sum4 = 0.0f;


	// loop unrolling of 4 at a time
	for (i = 0; i < length; i += 4){
		// parallel accumulators 
		sum1 += (u[i] * v[i]);
		sum2 += (u[i + 1] * v[i + 1]);
		sum3 += (u[i + 2] * v[i + 2]);
		sum4 += (u[i + 3] * v[i + 3]);
	}

	// picks up other items in arrays that werent picked up by previous for loop
	// finishes remaining elements
	for (; i < length; i++){
		sum1 = u[i] * v[i];
	}
	// adds the sums together
	*dest = sum1 + sum2 + sum3 + sum4;
}

void main(){
	int length = 5000; 
	// change length of array to change the time it takes to run the inner loops
	//
	// makes the arrays of the same length and the same elements
	float u[length];
	float v[length];
	float dest;
	for (int i = 0; i < length; ++i){
		u[i] = i;
		v[i] = i;
	}
	clock_t begin = clock(); // starts clock
	inner1(u, v, length, &dest);
	clock_t end = clock(); // ends clock
	double time = (double)(end - begin)/CLOCKS_PER_SEC; //calculates time spent 
	printf("Time spent inner1: %f\n", time);
	printf("%f\n", dest);

	clock_t start = clock();
	inner2(u, v, length, &dest);
	clock_t finish = clock();
	double time_spent = (double)(finish - start)/CLOCKS_PER_SEC;
	printf("Time spent inner 2: %f\n", time_spent);
	printf("%f\n", dest);
	
}
