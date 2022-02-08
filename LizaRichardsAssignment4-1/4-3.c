// Question 3:
//

#include <stdio.h>

long fact(long x){
	if (x <= 1){ //cmpq $1, %rdi, jle .L3
		return 1; // .L3: movl $1, %eax
	}
	
	//rbx is pushed onto the stack as an empty register to save a value that is to be used later
	//
	//x is moved into rbx, but it is not pushed onto the stack yet, 
	//it is only stored in the register, px is in rbx
	//
	//in the next call to the fact func, rbx is be given the the next input 
	//value with the push to the stack of value of x previously stored in rbx before it was deincremented
	//if the if the condition was not satisified
	
	long px = x; //movq %rdi, %rbx
	long fx = fact(x - 1); // leaq -1(%rdi), %rdi
	//a call to fact will implicitly push the call to fact onto the stack
	//
	//pops rbx before return and multiplies it by the next item in the stack, which is popped next until all
	//items and calls to func are popped from stack
	//
	//when a return is reached, it pops the previous call to fact func from stack implicitly
	//
	return px * fx; //imulq %rbx, %rax, popq %rbx
}

