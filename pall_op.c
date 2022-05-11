#include "monty.h"

/**
 * print_dlistint - function that prints all the elements of a dlist_t list.
 * @h: list given
 *
 * Return: number of nodes
 */

size_t print_dlistint(const dlistint_t *h)
{
	int node = 0;

	if (h == NULL)
		return (0);

	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
		node++;
	}

	return (node);
}

/**
 * pall_op - prints all values on the stack, starting from top of stack.
 * @stack: pointer to pointer to first node in list
 * @line_number: number of line
 * Return: void
 */

void pall_op(stack_t **stack, unsigned int line_number)
{
	void(line_number);

	if (*stack != NULL)
		print_dlistint(*stack);
}
