#include "snode.h"
#include "slist.h"
#include <string.h>

struct slist {
  struct snode *front; // front node
  struct snode *back;  // back node
};

struct slist *slist_create() {
  struct slist* pointer = (struct slist *)malloc(sizeof(struct slist));
  pointer->front = NULL;
  pointer->back = NULL;
  return pointer;
}

struct snode* slist_add_back(struct slist *l, char *str) {
  struct snode *newSnode = snode_create(str);
  if (l->back ==  NULL && l->front == NULL) {
    l->back = newSnode;
    l->front = newSnode;
  }
  else {
    struct snode* temp = l->front;
    while(temp != NULL && temp->next != NULL) {
      temp = temp->next;
    }

    temp->next = newSnode;
    l->back = newSnode;
  }
  return newSnode;
}

struct snode* slist_add_front(struct slist *l, char *str) {
  struct snode *newSnode = snode_create(str);
  if (l->front ==  NULL && l->back == NULL) {
    l->front = newSnode;
    l->back = newSnode;
  }
  else
  {
    newSnode->next = l->front;
    l->front = newSnode;
  }
  return newSnode;
}

struct snode* slist_find(struct slist *l, char *str) {
  struct snode *iteratedSnode= l->front;
  while (iteratedSnode != NULL) {
    if(strcmp(iteratedSnode->s, str) == 0) {
      break;
    }
    else{
      iteratedSnode = iteratedSnode->next;
    }
  }
  return iteratedSnode;

}

void slist_destroy(struct slist *l) {
  struct snode* iteratedSnode = l->front;
  struct snode* nextSnode;
  while (iteratedSnode != NULL) {
    nextSnode = iteratedSnode->next;
    snode_destroy(iteratedSnode);
    iteratedSnode = nextSnode;
  }
  free(l);
}
void slist_traverse(struct slist *l) {
  struct snode* temp = l->front;
   while (temp != NULL) {
      printf("%s ", temp->s);
      temp = temp->next;
   }
   printf("\n");
}

__uint32_t slist_length(struct slist *l) {
  __uint32_t num = 0;
  struct snode* temp = l->front;
  while (temp != NULL) {
    num += 1;
    temp = temp->next;
  }
  return num;
}

void slist_delete(struct slist *l, char *str) {
  struct snode *temp = l->front;
  struct snode *prev;
  if (temp != NULL && strcmp(temp->s, str) == 0) {
    l->front = temp->next;
    snode_destroy(temp);
    temp = l->front;
  }
 
  while (temp != NULL) {
    while (temp != NULL && strcmp(temp->s, str) != 0) {
      prev = temp;
      temp = temp->next;
    }

    if (temp == NULL) {
      return;
    }
    prev->next = temp->next;

    snode_destroy(temp);
    temp = prev->next;
  }
}