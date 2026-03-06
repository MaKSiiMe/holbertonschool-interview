#ifndef LIST_H
#define LIST_H

#include <stdlib.h>

/**
 * struct List - node of a doubly circular linked list
 * @str: string stored in the node
 * @prev: pointer to the previous element
 * @next: pointer to the next element
 */
typedef struct List
{
	char *str;
	struct List *prev;
	struct List *next;
} List;

List *add_node_end(List **list, char *str);
List *add_node_begin(List **list, char *str);

#endif /* LIST_H */
