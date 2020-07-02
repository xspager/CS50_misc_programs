#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int n;
  struct node *next;
} node;

void print_list(node*);
void add_node(node* list, int value);

int main(void) {
  node *list = NULL, *tmp = NULL;

  tmp = malloc(sizeof(node));
  list = tmp; // new node is the head of the list

  tmp->n = 42;

  printf("list->n = %d\n", list->n);

  tmp = malloc(sizeof(node));
  tmp->n = 666;
  list->next = tmp;

  printf("list->next->n = %d\n", list->next->n);

  tmp = malloc(sizeof(node));
  tmp->n = 69;
  list->next->next = tmp;

  printf("list->next->next->n = %d\n", list->next->next->n);

  // now we use the function add_node
  add_node(list, 10);
  add_node(list, 20);
  add_node(list, 30);
  add_node(list, 40);
  add_node(list, 50);

  print_list(list);

  return 0;
}

void print_list(node *list) {
  printf("Items on the list are: ");
  node *cur = list;
  while(cur->next) {
    printf("%d, ", cur->n);
    cur = cur->next;
  }
  printf("%d\n", cur->n);
}

void add_node(node* list, int value) {
  node *cur, *tmp;

  tmp = malloc(sizeof(node));
  tmp->n = value;
  cur = list;
  // find the last node
  while (cur->next) {
    cur = cur->next;
  }
  // place the new node in the end of the list
  cur->next = tmp;
}
