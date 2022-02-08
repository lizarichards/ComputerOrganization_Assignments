#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct ColorPoint{
	long a;
	long r;
	long g;
	long b;
};

long f(struct ColorPoint **points, int n){
	long sum = 0;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			sum += points[j][i].a;
			sum += points[j][i].r;
			sum += points[j][i].g;
			sum += points[j][i].b;
		}
	}
	return sum;
}

long g(struct ColorPoint **points, int n){
	long sum = 0;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			sum += points[i][j].a;
			sum += points[i][j].r;
			sum += points[i][j].g;
			sum += points[i][j].b;
		}
	}
	return sum;
}

struct ColorPoint** create2DArray(int n) {
	//Array to hold a pointer to the beginning of each row
	struct ColorPoint **points = 
		(struct ColorPoint **)malloc(n * sizeof(struct ColorPoint *));
	for (int i = 0; i < n; ++i){
		//Array to hold each row
		points[i] = (struct ColorPoint *)malloc(n * sizeof(struct ColorPoint));
		for (int j = 0; j < n; ++j){
			points[i][j].a = rand();
			points[i][j].r = rand();
			points[i][j].g = rand();
			points[i][j].b = rand();
		}
	}
	return points;
}

void free2DArray(struct ColorPoint** points, int n){
	for (int i = 0; i < n; ++i){
		free(points[i]);
	}
	free(points);
}

int main(){
	int size = 2048; // size of array (n x n)
	struct ColorPoint** new = create2DArray(size); // creates array
	clock_t start = clock(); // starts clock
	f(new, size); // calls f
	clock_t end = clock(); // ends clock
	double time_taken = (double)(end - start)/CLOCKS_PER_SEC; // calculates time taken
	printf("Time Taken f(): %f\n", time_taken);

	clock_t begin = clock(); // start clock
	g(new, size); // calls g
	clock_t finish = clock(); // ends clock
	double time = (double)(finish - begin)/CLOCKS_PER_SEC; // calculates time taken
	printf("Time Taken g(): %f\n", time);
	free2DArray(new, size); // frees mem used for array 

}

// g runs faster than f because there is better spacial locality therefore
// there are fewer misses and pulls from cache more which is more efficient
// than pulling from memory 
