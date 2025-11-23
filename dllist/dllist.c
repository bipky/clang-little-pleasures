#include <stdlib.h>

struct dllist {
  double data;
  struct dllist *prev, *next;
};

void insert_start(struct dllist *first, struct dllist *last, double value) {
  struct dllist *tmp;
  tmp = malloc(sizeof(struct dllist));
  tmp->data = value;
  tmp->prev = NULL;
  tmp->next = first;

  if (first)
    first->prev = tmp;
  else
    last = tmp;
  first = tmp;
}

void insert_end(struct dllist *first, struct dllist *last, double value) {
  struct dllist *tmp;
  tmp = malloc(sizeof(struct dllist));
  tmp->data = value;
  tmp->prev = last;
  tmp->next = NULL;
  if (last)
    last->next = tmp;
  else
    first = tmp;
  last = tmp;
}

void pop_first(struct dllist *first, struct dllist *last) {
  struct dllist *tmp;
  if (first) {
    tmp = first;
    first = first->next;
    if (first)
      first->prev = NULL;
    else
      last = NULL;
    free(tmp);
  }
}

void pop_last(struct dllist *first, struct dllist *last) {
  struct dllist *tmp;
  if (last) {
    tmp = last;
    last = last->prev;
    if (last)
      last->prev = NULL;
    else
      first = NULL;
    free(tmp);
  }
}

void clean_list(struct dllist *first, struct dllist *last) {
  if (first) {
    first = first->next;
    while (first) {
      free(first->prev);
      first = first->next;
    }
    free(last);
    last = NULL;
  }
}

int main(int argc, char **argv) { struct dllist *first = NULL, *last = NULL; }
