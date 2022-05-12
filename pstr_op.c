#include "monty.h"

/**
 * pstr_op - prints the string starting from top of stack followed by \n
 * @stack: pointer to pointer to first node in list
 * @line_number: number of line
 * Return: void
 */

void pstr_op(stack_t **stack, __attribute__((unused))unsigned int line_number)
{

	int node = 0;

	if (*stack == NULL || stack == NULL)
	{
		printf("\n");
		return;
	}
	
	while (stack && (*stack)->n != 0 && (*stack)->n >= 0 && (*stack)->n <= 127)
	{
		printf("%c", (*stack)->n);
		(*stack) = (*stack)->next;
		node++;
	}
	printf("\n");

}
