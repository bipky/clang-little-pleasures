#include <stdio.h>
#include <stdlib.h>

struct list_item {
  int value;
  struct list_item *next;
};

struct list_item *int_array_to_list(const int *array, int length) {
  struct list_item *first = NULL, *tmp;
  int i;
  for (i = length - 1; i >= 0; i--) {
    tmp = malloc(sizeof(struct list_item));
    tmp->value = array[i];
    tmp->next = first;
    first = tmp;
  }
  return first;
}

struct list_item *int_array_to_list_rec(const int *array, int length) {
  struct list_item *tmp;
  if (!length)
    return NULL;
  tmp = malloc(sizeof(struct list_item));
  tmp->value = *array;
  tmp->next = int_array_to_list(array + 1, length - 1);
  return tmp;
}

int list_sum(const struct list_item *first) {
  int result = 0;
  const struct list_item *current;

  for (current = first; current; current = current->next) {
    result += current->value;
  }
  return result;
}

void print_list(struct list_item *first) {
  struct list_item *current = first;
  int i = 0;

  for (current = first; current; current = current->next, i++) {
    printf("Element %d = %d\n", i, current->value);
  }
}

void clear_list(struct list_item *first) {
  while (first) {
    struct list_item *current = first;
    first = first->next;
    free(current);
  }
}

void delete_negatives(struct list_item **pcurrent) {
  while (*pcurrent) {
    if ((*pcurrent)->value < 0) {
      struct list_item *temp = *pcurrent;
      *pcurrent = (*pcurrent)->next;
      free(temp);
    } else {
      pcurrent = &(*pcurrent)->next;
    }
  }
}

int main(int argc, char **argv) {
  int array_size, i;
  int *array;
  struct list_item *list;

  printf("Input array size: ");
  scanf("%d", &array_size);
  array = malloc(sizeof(int) * array_size);
  printf("Input array elements: ");
  for (i = 0; i < array_size; i++) {
    scanf("%d", &array[i]);
  }

  list = int_array_to_list_rec(array, array_size);
  print_list(list);

  printf("Sum of elements: %d", list_sum(list));

  delete_negatives(&list);

  print_list(list);

  clear_list(list);

  return 0;
}
