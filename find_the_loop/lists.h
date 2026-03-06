#ifndef LISTS_H
#define LISTS_H

#include <stdlib.h>

/**
 * struct listint_s - singly linked list
 * @n: integer
 * @next: points to the next node
 *
 * Description: node structure for a singly linked list
 */
typedef struct listint_s
{
    int n;
    struct listint_s *next;
} listint_t;

/* utility functions used by the test main and library */
size_t print_listint_safe(const listint_t *h);
listint_t *add_nodeint(listint_t **head, const int n);
void free_listint_safe(listint_t **h);

/* prototype for the loop detection function */
listint_t *find_listint_loop(listint_t *head);

#endif /* LISTS_H */
