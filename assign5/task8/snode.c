#include <stdio.h>
#include "snode.h"
#include <string.h>
#include <stdlib.h>

struct snode *snode_create(void *d, size_t data_size) 
{
 //TODO: implement snode_create, change the prototype to
 //match with header file
 //return node;
 struct snode* pointer = (struct snode *)malloc(sizeof(struct snode));
 pointer->data = malloc(data_size);
 strcpy(pointer->data, d);;

 pointer->next = NULL;
 return pointer;
  
}
void snode_destroy(struct snode * pointer) 
{
  free(pointer->data);
  free(pointer);

 //TODO: implement snode_destroy
 
};