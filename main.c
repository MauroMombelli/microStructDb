#include <stdio.h>

#include "static_generic/engine.h"

/*run, code, run!*/
int main()
{
	struct A a_copy;
	struct B b_copy;
	struct C c_copy;
	
	get_A(&a_copy);
	get_B(&b_copy);
	get_C(&c_copy);
	
	printf("STRUCTURE IN ARRAY BEFORE INITIALIZATION\n");
	printf("A = %d\n", a_copy.a1);
	printf("B = %f\n", b_copy.b1);
	printf("C = %x\n", c_copy.c1);
	
	a_copy.a1 = -1;
	b_copy.b1 = 2.3;
	c_copy.c1 = 3;
	
	printf("STRUCTURE CHANGED TO\n");
	printf("A = %d\n", a_copy.a1);
	printf("B = %f\n", b_copy.b1);
	printf("C = %x\n", c_copy.c1);
	
	printf("STRUCTURE SAVED\n");
	put_A(&a_copy);
	put_B(&b_copy);
	put_C(&c_copy);
	
	get_A(&a_copy);
	get_B(&b_copy);
	get_C(&c_copy);
	
	printf("STRUCTURE LOADED\n");
	printf("A = %d\n", a_copy.a1);
	printf("B = %f\n", b_copy.b1);
	printf("C = %x\n", c_copy.c1);
	
	a_copy.a1 = 1000;
	b_copy.b1 = -50.576;
	c_copy.c1 = 700;
	
	printf("STRUCTURE CHANGED TO\n");
	printf("A = %d\n", a_copy.a1);
	printf("B = %f\n", b_copy.b1);
	printf("C = %x\n", c_copy.c1);
	
	get_A(&a_copy);
	get_B(&b_copy);
	get_C(&c_copy);
	
	printf("STRUCTURE RELOADED WITHOUT SAVING\n");
	printf("A = %d\n", a_copy.a1);
	printf("B = %f\n", b_copy.b1);
	printf("C = %x\n", c_copy.c1);
	
	
	return 0;
}
