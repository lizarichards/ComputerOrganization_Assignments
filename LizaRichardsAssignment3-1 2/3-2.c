// Question 2:
//

#include <stdio.h>


long f(long x, long y, long z){
	// x: %rdi, y: %rsi, z: %rdx, return: %rax
	// src, dest 
	z = z + y; // addq %rsi, %rdx (dest = dest + src)
	x = z * x; // imulq %rdx, %rdi (dest = dest * src)
	z = z << 63; // salq $63, %rdx (dest = dest << src)
	z = z >> 63; //sarq $63, %rdx (dest = dest >> src)
	return x ^ z; // xorq %rdx, %rax (dest = dest ^ src)
}

int main(){
	
	f(1, 2, 4); //should be 6
	f(3, 5, 7); //should be 36
	f(10, 20, 30); //should be 500
}

