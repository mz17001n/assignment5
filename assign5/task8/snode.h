#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef _slist_H_
#define _slist_H_

struct snode {
  void * data;
  struct snode *next;
};

//TODO: change prototypes of functions to remove
//length
struct snode *snode_create(void *d, size_t data_size) ; 
void snode_destroy(struct snode * s) ;
 
#endif