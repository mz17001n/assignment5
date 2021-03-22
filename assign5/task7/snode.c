#include <stdio.h>
#include "snode.h"
#include <string.h>
#include <stdlib.h>

struct snode *snode_create(char *s) 
{
 //TODO: implement snode_create, change the prototype to
 //match with header file
 //return node;
 struct snode* pointer = (struct snode *)malloc(sizeof(struct snode));
 pointer->s = (char *)malloc((strlen(s) + 1)*sizeof(char));
 strcpy(pointer->s, s);
 pointer->next = NULL;
 return pointer;
  
}
void snode_destroy(struct snode * pointer) 
{
  free(pointer->s);
  free(pointer);

 //TODO: implement snode_destroy
 
};
 
