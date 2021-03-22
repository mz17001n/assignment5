#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef _slist_H_
#define _slist_H_

struct snode {
  //TODO: change str to dynamic allcoation
  char *s;
  struct snode *next;
};

//TODO: change prototypes of functions to remove
//length
struct snode *snode_create(char *s) ; 
void snode_destroy(struct snode * s) ;
 
#endif