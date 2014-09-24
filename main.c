#include <memory.h>
#include <stdio.h>
#include <stdlib.h>

/* BEGIN: just some struct to test, fell free to move them on external header file */
struct A
{
	int a1;
	long a2;
};

struct B
{
	float b1;
	char b2[6];
};

struct C
{
	unsigned int c1;
	double c2[5];
};
/* END: just some struct to test, fell free to move them on external header file */

/* this macro will create the right X macro element, and also initiliaze the "anonymous" struct */
#define ADD_STRUCT_TO_ARRAY(xu) X(xu, &(struct xu){})SEP

/* BEGIN: add or remove your own struct here! fell free to move them on external header file 
 * just need to pass struct name without "struct" to ADD_STRUCT_TO_ARRAY macro */
#define GENERIC_TABLE \
	ADD_STRUCT_TO_ARRAY(A) \
	ADD_STRUCT_TO_ARRAY(B) \
	ADD_STRUCT_TO_ARRAY(C)
/* END: add or remove your own struct here! */

/* here we initialize the enum, where the type of the struct is the key, and the value its position in the array */
#define SEP ,
#define X(a,b) a
enum STRUCT {
	GENERIC_TABLE
};
#undef X

/* here we initalize the array of structure */
#define X(a,b) b
void * const generic[] =
{
	GENERIC_TABLE
};
#undef X
#undef SEP

/* here we create all the getter function. add here your array locking code */
#define SEP ;
#define X(a,b) void get_##a(struct a * dest){memcpy(dest, generic[a], sizeof(struct a) );} 
GENERIC_TABLE
#undef X
#undef SEP

/* here we create all the putter function. add here your array locking code */
#define SEP ;
#define X(a,b) void put_##a(struct a * source){memcpy(generic[a], source, sizeof(struct a) );}
GENERIC_TABLE
#undef X
#undef SEP

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
