#include "monty.h"

/**
 * pstr_op - prints the string starting from top of stack followed by \n
 * @stack: pointer to pointer to first node in list
 * @line_number: number of line
 * Return: void
 */

void pstr_op(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *node = *stack;

	if (*stack == NULL || stack == NULL)
	{
		printf("\n");
		return;
	}
	while (node && node->n != 0 && node->n >= 0 && node->n <= 127)
	{
		printf("%c", node->n);
		node = node->next;
	}
	printf("\n");

}
