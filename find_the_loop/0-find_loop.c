#include "lists.h"

/**
 * find_listint_loop - Finds the start of a loop in a linked list
 * @head: Pointer to the head of the list
 *
 * Return: Address of the node where the loop begins, or NULL if none
 *
 * Description: Uses Floyd's Tortoise and Hare algorithm. Only two
 * variables are declared in the function (slow and fast pointers).
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *slow, *fast;

	if (!head || !head->next)
		return (NULL);

	slow = head->next;
	fast = head->next->next;
	while (fast && slow && fast != slow)
	{
		slow = slow->next;
		fast = fast->next;
		if (fast)
			fast = fast->next;
	}

	if (!fast || !slow)
		return (NULL);

	slow = head;
	while (slow != fast)
	{
		slow = slow->next;
		fast = fast->next;
	}

	return (slow);
}
