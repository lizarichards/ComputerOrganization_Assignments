// Question 1
//

#include <stdio.h>
#include <stdlib.h>

struct IntArray {
	int length;
	int *dataPtr;
};

struct IntArray* mallocIntArray(int length){
	// allocates, initializes and returns a pointer to a new struct IntArray
	
	struct IntArray *arrayPtr = (struct IntArray *)malloc(sizeof(struct IntArray));
	arrayPtr->length = length; //resets the length
        arrayPtr->dataPtr = ((int *)malloc(length * sizeof(int))); //type casting to int pointer
	return arrayPtr;    
}

void freeIntArray(struct IntArray *arrayPtr){
	// frees the instance dataPtr and frees the instance
	free(arrayPtr->dataPtr);
	free(arrayPtr);
}

void readIntArray(struct IntArray *array){

	int count = 0;
	int pos = 0;

	while (count <  array->length){ // iterates through the same number of times thats specified by length
		printf("Enter int: "); //gets user input
		char num[BUFSIZ];
		fgets(num, BUFSIZ, stdin); //stores user input in file
		long value = strtol(num, NULL, 10); // changes user input from string to long int
		while (value <= 0) { //if value is not a positive int, then prints error and prompts input again
			printf("Invalid Input\n");
			printf("Enter int: ");
			fgets(num, BUFSIZ, stdin);
			value = strtol(num, NULL, 10);
		} 
		array->dataPtr[count] = value; // stores the users input in the array
		count++; 
	}
}


void swap(int *xp, int *yp){
	//swaps int value stored at the xp and yp pointers
	long t0 = *xp;
	long t1 = *yp;
	*xp = t1;
	*yp = t0;
}

void sortIntArray(struct IntArray *array){

	long a, b, min;

	//loops through array and compares items in it and changes the min variable if the next item is 
	//less than the current min
	// sorts array from smallest to biggest 
	for (a = 0; a < array->length - 1; a++){ //loops through array
		min = a; //sets min to first item initially and then iterates through each next item in array
		for (b = a + 1; b < array->length; b++){ // sets b to the next item after a in array
			if (array->dataPtr[b] < array->dataPtr[min]){ //compares min and b, changing min if <
				min = b;
			}
		}
		//calls swap function to swap the places of items in the array
		swap(&array->dataPtr[min], &array->dataPtr[a]); 
	}
}

void printIntArray(struct IntArray *array){
	int i;
	printf("[ "); // makes sure the array is printed in brackets
	for (i = 0; i <= array->length - 1; i++){ //loops through each item in the array until the end of it
		printf("%d", array->dataPtr[i]); // prints individual item 
		if (i < array->length - 1){ //pritns comma in between each item unless last item
			printf(", ");
		} else {
			printf(" ");
		}
	}
	printf("]\n");
}

int main(){
	
	// gets the user input for length
	char length[BUFSIZ]; 
	printf("Enter length: ");
	fgets(length, BUFSIZ, stdin); // obtains the user input and stores it in a file
	long size = strtol(length, NULL, 10); // changes the length from a string to a long int

	// if the users input is not a positive int, prints error message and asks for new input
	while (!(size > 0)){
		printf("Invalid Input");
		printf("Enter length: ");
		fgets(length, BUFSIZ, stdin);
		size = strtol(length, NULL, 10);
	}

	struct IntArray* new =  mallocIntArray(size); // creates an array
	readIntArray(new); //prompts user to fill array
	sortIntArray(new); //sorts array numerically
	printIntArray(new); //prints array
	freeIntArray(new); //frees array
	return 0;	
}

// selection sort citation: https://www.geeksforgeeks.org/selection-sort/
// strtol citation: https://www.tutorialspoint.com/c_standard_library/c_function_strtol.htm

