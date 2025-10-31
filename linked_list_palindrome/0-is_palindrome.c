#include "lists.h"
#include <stddef.h>

/**
 * reverse_list - Reverses a singly linked list
 * @head: Pointer to the head of the list
 *
 * Return: Pointer to the new head of the reversed list
 */
listint_t *reverse_list(listint_t *head)
{
	listint_t *prev = NULL;
	listint_t *current = head;
	listint_t *next = NULL;

	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}

	return (prev);
}

/**
 * is_palindrome - Checks if a singly linked list is a palindrome
 * @head: Double pointer to the head of the list
 *
 * Return: 1 if it is a palindrome, 0 otherwise
 */
int is_palindrome(listint_t **head)
{
	listint_t *slow, *fast, *second_half, *first_half;
	int is_palin = 1;

	if (head == NULL || *head == NULL)
		return (1);

	slow = *head;
	fast = *head;

	/* Find the middle of the list */
	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
	}

	/* Reverse the second half */
	second_half = reverse_list(slow);
	first_half = *head;

	/* Compare both halves */
	while (second_half != NULL)
	{
		if (first_half->n != second_half->n)
		{
			is_palin = 0;
			break;
		}
		first_half = first_half->next;
		second_half = second_half->next;
	}

	return (is_palin);
}
