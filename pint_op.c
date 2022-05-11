#include "monty.h"

/**
 * pint_op - prints the value on the top of the stack
 * @stack: pointer to pointer to first node in list
 * @line_number: number of line
 * Return: void
 */

void pint_op(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || stack == NULL)
		error_handler(5, NULL);

	printf("%d\n", (*stack)->n);
}
