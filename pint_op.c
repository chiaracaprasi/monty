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
	{
		dprintf(STDERR_FILENO, PINT_FAIL, line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
