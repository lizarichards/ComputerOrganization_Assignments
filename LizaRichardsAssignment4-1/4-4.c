// Question 4:
//

#include <stdio.h>
#define N 4

typedef long array_t[N][N];

/*
.L3:
	movq (%rax), %rcx # *t1 = &a[i][j] 
	movq (%rdx), %rsi # *t2 = &a[j][i]
	movq %rsi, (%rax) # *a[i][j] = t2 ((*rax) = rsi)
	movq %rcx, (%rdx) # *a[j][i] = t1 ((*rdx) = rcx)
	addq $8, %rax # i += 8 (i++)
	addq $32, %rdx # j += 32 (N)
	cmpq %r9, %rax # sets flags for i - N
	jne .L3 #execute the inner loop

*/

void transpose(array_t a){
	for (long i = 0; i < N; ++i){
		long *row = &a[i][i]; // points to elements in row i 
		long *col = &a[i][i]; // points to elements in col i
		long *stop = &a[N][i]; // marks stopping point for column

		do { // loop that swaps the cols and rows, actually transposes the matrix
			long t1 = *col; 
			long t2 = *row;

			*col = t2;
			*row = t1;

			row++; // moves row pointer to next column
			col += N; // moves column pointer to next row


		} while (col != stop); //testing for stopping point
	}	

}
//prints the transposed matrix properly
void printArray(array_t a){
	printf("{");
	for (int x = 0; x < N; x ++){
		printf("{");
		for(int y = 0; y < N; y++){
			printf("%d", a[x][y]);
			if (y < N - 1)
				printf(", ");
			else 
				printf("");
		}
		printf("}");
	}
	printf("}");
}


void main(){

	long array_t[N][N] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
	printf("Original:\n");
	printArray(array_t);
	printf("\n");
	printf("Transposed:\n");
	transpose(array_t);
	printArray(array_t);

}
