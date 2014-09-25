#include "user_data/struct.h"

/* this macro will create the right X macro element, and also initiliaze the "anonymous" struct */
#define ADD_STRUCT_TO_ARRAY(xu) X(xu, &(struct xu){})SEP

/* here we initialize the enum, where the type of the struct is the key, and the value its position in the array */
#define SEP ,
#define X(a,b) a
enum STRUCT {
	#include "user_data/array_initialization.h"
};
#undef X

/* here we initalize the array of structure */
#define X(a,b) b
void * const generic[] =
{
	#include "user_data/array_initialization.h"
};
#undef X
#undef SEP

/* here we create all the getter function. add here your array locking code */
#define SEP ;
#define X(a,b) void get_##a(struct a * dest){memcpy(dest, generic[a], sizeof(struct a) );} 
#include "user_data/array_initialization.h"
#undef X
#undef SEP

/* here we create all the putter function. add here your array locking code */
#define SEP ;
#define X(a,b) void put_##a(struct a * source){memcpy(generic[a], source, sizeof(struct a) );}
#include "user_data/array_initialization.h"
#undef X
#undef SEP 
