#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * add_nodeint - adds a node at the beginning of a listint_t list
 * @head: address of pointer to head
 * @n: integer value to add
 * Return: address of new node or NULL
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
    listint_t *new;

    new = malloc(sizeof(listint_t));
    if (new == NULL)
        return (NULL);

    new->n = n;
    new->next = *head;
    *head = new;
    return (new);
}

/**
 * print_listint_safe - prints a listint_t list safely (loop-aware)
 * @h: pointer to the head of the list
 * Return: number of nodes printed
 */
size_t print_listint_safe(const listint_t *h)
{
    const listint_t *current = h;
    const listint_t **seen = NULL;
    size_t count = 0, cap = 0, i;

    while (current)
    {
        for (i = 0; i < count; i++)
        {
            if (seen[i] == current)
            {
                printf("-> [%p] %d\n", (void *)current, current->n);
                free(seen);
                return (count);
            }
        }
        if (count == cap)
        {
            cap = cap ? cap * 2 : 16;
            seen = realloc(seen, cap * sizeof(*seen));
            if (seen == NULL)
                exit(98);
        }
        seen[count++] = current;
        printf("[%p] %d\n", (void *)current, current->n);
        current = current->next;
    }
    free(seen);
    return (count);
}

/**
 * free_listint_safe - frees a listint_t list safely (handles loops)
 * @h: address of pointer to head
 *
 * After freeing, *h is set to NULL.
 */
void free_listint_safe(listint_t **h)
{
    listint_t *current, *next;
    const listint_t **seen = NULL;
    size_t count = 0, cap = 0, i;

    if (h == NULL || *h == NULL)
        return;

    current = *h;
    while (current)
    {
        for (i = 0; i < count; i++)
        {
            if (seen[i] == current)
            {
                *h = NULL;
                free(seen);
                return;
            }
        }
        if (count == cap)
        {
            cap = cap ? cap * 2 : 16;
            seen = realloc(seen, cap * sizeof(*seen));
            if (seen == NULL)
                exit(98);
        }
        seen[count++] = current;
        next = current->next;
        free(current);
        current = next;
    }
    *h = NULL;
    free(seen);
}