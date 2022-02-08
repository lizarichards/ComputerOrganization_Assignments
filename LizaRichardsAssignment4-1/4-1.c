// Question 1:
//

#include <stdio.h>

//x86-64 code:
// loop:
// 	movq %rsi, %rcx // move b into rcx
// 	movl $1, %eax // mask, because we know it's not result since result = 0
// 	movl $0 %edx // result because we initialize result as 0
// .L2:
// 	testq %rax, %rax // as long as mask is not 0, then jump into the loop, otherwise don't jump into loop
// 	je .L4
// 	movq %rax, %r8 // mask moves into r8
// 	andq %rdi, %r8 // a & r8, just moved mask to r8 so a & mask
// 	orq %r8, %rdx // r8 | result and r8 = mask so mask | result
// 	salq %cl, %rax //shift rax by cl, cl = rcx and moved rsi to rcx, so cl = b
// 	jmp .L2
// .L4:
// 	movq %rdx, %rax // else loop, the result is still 0 and return 0
// 	ret

long loop(long a, long b){
	//eax is the cheat sheet
	long result = 0;
	for (long mask = 1; mask != 0; mask <<= b){
		result |= (a & mask);
	}

	//printf("%d\n", result);
	return result;
}

void main(){
	loop(1, 5); // 1
	loop(2, 4); // 0
	loop(3, 3); // 1
	loop(4, 2); // 4
	loop(5, 1); // 5
}
