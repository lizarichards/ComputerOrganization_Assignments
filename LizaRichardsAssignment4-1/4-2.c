// Question 2:
//

#include <stdio.h>

/*
int sum(int from, int to){
	int result = 0;
	if (from > to) 
		goto done;

	loop:
	{
		result += from;
		++from;
	}
		
	if (from <= to) 
		goto loop;
	done: 
		return result;
}
*/

long sum(long from, long to){
	// Declare and initialize result var 
	long result = 0;

	//Ensure that argument *from* is in %rdi,
	//argument *to* is in %rsi, *result* is in %rax
	__asm__ ("movq %0, %%rdi # from in rdi;" :: "r" ( from ));
	__asm__ ("movq %0, %%rsi # to in rsi;" :: "r" ( to ));
	__asm__ ("movq %0, %%rax # result in rax;" :: "r" ( result ));
	
	// Your x86-64 code goes below - comment each instruction
	__asm__(
			//TODO - Replace the two lines below with add, compare
			// jump instructions, labels, etc as necessary to implement
			// the loop

			".L3:" // loop
				// if from > to, then move from into result and return result
				"addq %rdi, %rax;" // adds result and from
				"addq $1, %rdi;" // increments from by 1
				"cmpq %rsi, %rdi;" // compares from and to
				"jle .L3;" // signal to enter loop if from <= to from previous compare

	       );

	//Esure that *result* is in %rax for return
	__asm__("movq %%rax, %0 #result in rax;" : "=r" ( result ));
	printf("%d\n", result);
	return result;

}

void main(){
	sum(1, 6); // 21
	sum(3, 5); // 12
	sum(5, 3); // 5
}
