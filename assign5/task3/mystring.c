/* Include the system headers we need */
#include <stdlib.h>
#include <stdio.h>

/* Include our header */
#include "mystring.h"

/* Define what our struct is */
struct mystring_t {
	size_t size;
	char *data;
};

/* Utility function to handle allocation failures. In this
   case we print a message and exit. */
static void allocation_failed() {
    fprintf(stderr, "Out of memory.\n");
    exit(1);
}

/* Bad example of how to create a new mystring */
mystring_t *bad_string_new() {
	/* Create the string and a pointer to it */
        /*This is a bad constructor as v gets destroyed once contructor returns*/
	mystring_t *retval, v;
	retval = &v;

	/* Initialize attributes */
	retval->size = 1; //why size+1? size is the actual char lenght. 
			  //we must reseve an extra space for null
	retval->data = (char*) malloc((retval->size+1)*sizeof(char));
	if (retval->data == NULL) {
		allocation_failed();
	}

	retval->data[0] = ' ';
	retval->data[retval->size] = '\0';
	return retval;
}

/* Another suboptimal way of creating a string */
mystring_t also_bad_string_new() {
	/* Create the string */
	/*why is this bad? does v get destroyed upon returning? */
	mystring_t s;

	/* Initialize attributes */
	s.size = 1; //why size+1? an extra space for null
	s.data = (char*) malloc((s.size+1)*sizeof(char));
	if (s.data == NULL) {
		allocation_failed();
	}
	s.data[0] = ' ';
	s.data[s.size] = '\0';
	return s;
}

/* Create a new string with a size (length) of 1
   and set its single component to zero... the
   RIGHT WAY */
mystring_t *mystring_new() {
	mystring_t *retval;
	//YOUR CODE HERE
  retval = (mystring_t*)malloc(sizeof(struct mystring_t));
  retval->size = 1;
  retval->data = (char*) malloc((retval->size+1)*sizeof(char));
  retval->data[0] = ' ';
  retval->data[1] = '\0';
  return retval;
}

/* Return the value at the specified location/component "loc" of the mystring */
char mystring_get(mystring_t *s, size_t loc) {
	//YOUR CODE HERE
  if(loc < 0 || loc >= s->size) {
	  return ' ';
  } else {
	  return s->data[loc];
  }
}

/* Free up the memory allocated for the passed mystring.
   Remember, you need to free up ALL the memory that was allocated. */
void mystring_delete(mystring_t *s) {
	/* YOUR CODE HERE */
  free(s->data);
  free(s);
}

int mystring_get_len(mystring_t *s) {
	/* YOUR CODE HERE */
  return s->size;
}

char* mystring_get_data(mystring_t *s) {
	/* YOUR CODE HERE*/
	return s->data;
}
void mystring_cat(mystring_t *s, char *s2) {
	/* YOUR CODE HERE*/
     size_t l, i, len;

	//Get string s length
	size_t myStrLen = s->size;
	//compute string s2 lenth
	for (l = 0; s2[l] != '\0'; ++l);
	len = myStrLen + l;
	s->data = (char *)realloc(s->data, (len + 1) * sizeof(char));

	for (i = 0; i<l; i++) {
		s->data[i + myStrLen] = s2[i];		
	}

	s->data[len] = '\0';
	s->size = len;
}

/* Set a value in the mystring. If the extra memory allocation fails, call
   allocation_failed(). Unset space should be value of space */
void mystring_set(mystring_t *s, size_t loc, char value) {
	/* YOUR CODE HERE*/
    size_t i;
	char *str = NULL;

	if (loc >= s->size)
	{
		str = (char*)malloc((loc + 1)*sizeof(char));
		if (str == NULL) {
			allocation_failed();
		}

		for (i = 0; i < loc; i++)
			str[i] = ' ';

		for (i = 0; i < s->size; ++i)
		{
			str[i] = s->data[i];
		}
		free(s->data);
		s->data = str;
		s->size = loc + 1;
	}

	s->data[loc] = value;
	return;
}