#include <stdio.h>
#include <stdlib.h>

struct node {
  int value;
  struct node *left, *right;
};

void btree_print_rec(struct node *root) {
  if (!root)
    return;
  btree_print_rec(root->left);
  printf("%d ", root->value);
  btree_print_rec(root->right);
}

void btree_print_norec(struct node *root) {
  enum state { start, left_visited, completed };
  struct backpath {
    struct node *ptr;
    enum state st;
    struct backpath *next;
  };
  struct backpath *bp, *temp;
  bp = malloc(sizeof(*bp));
  bp->ptr = root;
  bp->st = start;
  bp->next = NULL;
  while (bp) {
    switch (bp->st) {
    case start:
      bp->st = left_visited;
      if (bp->ptr->left) {
        temp = malloc(sizeof(*temp));
        temp->ptr = bp->ptr->left;
        temp->st = start;
        temp->next = bp;
        bp = temp;
        continue;
      }
    case left_visited:
      printf("%d ", bp->ptr->value);
      bp->st = completed;
      if (bp->ptr->right) {
        temp = malloc(sizeof(*temp));
        temp->ptr = bp->ptr->right;
        temp->st = start;
        temp->next = bp;
        bp = temp;
        continue;
      }
    case completed:
      temp = bp;
      bp = bp->next;
      free(temp);
    }
  }
}

void btree_add(struct node **root, int n) {
  if (!*root) {
    *root = malloc(sizeof(**root));
    (*root)->value = n;
    (*root)->left = NULL;
    (*root)->right = NULL;
  }
  if ((*root)->value == n)
    return;
  if (n < (*root)->value)
    btree_add(&(*root)->left, n);
  else
    btree_add(&(*root)->right, n);
}
