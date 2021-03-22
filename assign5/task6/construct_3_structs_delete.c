#include<stdio.h>
#include<stdlib.h>
#include "snode.h"
typedef struct snode node_t;

node_t * setup() {
    //TODO:copy setup func from task2
    node_t * head ;
    node_t * node1;
    node_t * node2;
    node_t * node3;
    node1 = (node_t *)malloc(sizeof(node_t));
    node2 = (node_t *)malloc(sizeof(node_t));
    node3 = (node_t *)malloc(sizeof(node_t));
    strcpy(node1->str, "hello");
    node1->length = 5;
    node1->next = NULL;
    strcpy(node2->str, "there");
    node2->length = 5;
    node2->next = NULL;
    strcpy(node3->str, "prof");
    node3->length = 4;
    node3->next = NULL;
    node1->next = node2;
    node2->next = node3;
    head = node1;
    //TODO:head declared for you
    //Allocate three more pointers
    //head for the first Node, and temporary pointers node1, node2 and node3
    //Allocate three node pointees and store references to them in the three pointers
    //Dereference each pointer to store the appropriate number and string into the length and str fields in its pointee.
    //Dereference each pointer to access the .next field in its pointee, 
    //and use pointer assignment to set the .next field to point to the appropriate Node. 
    
   return head;
}

void teardown(node_t* head) {
  free(head->next->next);
  free(head->next);
  free(head);
    //TODO: free all dynamic memory you requested.
    //Please complete the prototype of teardown.
    //You are not allowed to use globals
}

 void add(node_t ** head, char * str, int length){
     //TODO: implement add to add a new node to front, pointed by head
    struct snode* new_node = (struct snode*) malloc(sizeof(struct snode));
    new_node->next = *head;
    new_node->length = length;
    strcpy(new_node->str, str);
    (*head) = new_node;
 }
void delete_node_at(node_t ** head, int idx) {
    //TODO: implement delete a node based on index
	//deletes a node at index idx, which ranges from zero to the length of the list - 1.
  node_t * cur = *head;
  node_t * prev = NULL;
  int i = 0;
  while(cur != NULL) {
    if (i == idx) {
      if (prev != NULL) {
        prev->next = cur->next;
        free(cur);
        return;
      }
      else {
        *head = (*head)->next;
        free(cur);
        return;
      }
    }
    prev = cur;
    cur = cur->next;
    i++;
  }
  
} 
void delete_node_key(node_t **head, char * key) {
    //TODO: implement delete a node based on key
	//given a certain key, find and delete. 
  node_t * cur = *head;
  node_t * prev = NULL;
  char * str = str;
  while(cur != NULL) {
    if (strcmp(cur->str, key) == 0) {
      if (prev != NULL) {
        prev->next = cur->next;
        free(cur);
        return;
      }
      else {
        *head = (*head)->next;
        free(cur);
        return;
      }
    }
    prev = cur;
    cur = cur->next;
  }
}
void dump_all(node_t*);
int main (int argc, char ** argv) {
    node_t * head = setup();
    add(&head, "hi", 2);
    delete_node_key(&head, "prof");
    delete_node_at(&head, 0);
    dump_all(head);
    teardown(head);
    return 0;
}

void dump_all(node_t * head) {
    printf("head -> ");
    node_t * cur = head;
    while(cur != NULL) {
        printf("%s ", cur->str);
	cur = cur->next;
    }
    printf("\ndone\n ");
}