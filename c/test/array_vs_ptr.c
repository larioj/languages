// Array version
int main() {
  int a[3];
  a[2] = 5;
}

// Pointer version on different file.
// placed here for convenience.
/* int main() {
   int a[3];
   int *p = a;
   p[2] = 5;
 } */

// End Notes
/* I have always been curious about what the
 * differences between pointers and arrays are
 * in c. I always thought that the were essentially
 * the same thing, except for some very strange edge
 * cases. I wrote these two little functions to see what
 * exactly the differences were.
 *
 * I compiled them into assembly code and diffed them.
 * Here are the results:
 *
 * 17,19c17,22
 * < 	movq	(%rax), %rcx  // array version
 * < 	movq	%rcx, -8(%rbp)
 * < 	movl	$5, -12(%rbp)
 * ---
 * > 	leaq	-20(%rbp), %rcx  // Pointer version
 * > 	movq	(%rax), %rdx
 * > 	movq	%rdx, -8(%rbp)
 * > 	movq	%rcx, -32(%rbp)
 * > 	movq	-32(%rbp), %rcx
 * > 	movl	$5, 8(%rcx)
 *
 * Turns out they are fundamentally different.
 * The end result might be the same, but the
 * way that the compiler gets there is way different.
 * We can see that on the ptr version the compiler
 * generates code with a load effective address (leaq)
 * instruction. It is actually doing the pointer arithmetic
 * to get to the end result, while the array version is not.
 * The pointer version also takes more operations to accomplish
 * the task. 
 *
 * From this it appears that using arrays is more efficient than
 * ptrs. I'll keep this in mind when coding.
 */
