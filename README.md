microStructDb
=============

this is a fast example of a STATIC struct's based DB in C (ansi?)

PLEASE NOTE:
locking function are MISSING because every system has its own, and this is thinked to fit into embedded device, this is because i wanted it statically defined, and with get and put function with make type check on compile time.

you will need to change the A B and C struct with desired struct (no pointer allowed! only array and variables), even including external header.
then change ADD_STRUCT_TO_ARRAY(A) accordly to your need.
Even ADD_STRUCT_TO_ARRAY may be moved to external file, and icaplulated into #IFDEF block to build your own compile time Struct DB.

the preprocessor directive will the initialize some magic, and generate get_A(struct A *) and put_A(struct A *) function, witch you will have to use to get and store the structure to the DB

just add your locking function inside the get and put function generator to archive "full db".

this will be the base of ongoin development of custom firmaware for custom drones;

this code is based on multiple input, see full story here http://stackoverflow.com/questions/26005389/array-of-struct-and-sizeof

thanks to +FrancescoNero for its invaluable help
