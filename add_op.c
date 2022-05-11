#include "monty.h"

/**
 * add_op - adds the first two ints from a stack_t list
 * @stack: pointer to the head of the list
 * @line_number: line no\umber opcode was found in
 * Return: Nothing
 */
void add_op(stack_t **stack, unsigned int line_number)
{
	int n;

	if (*stack == NULL || (*stack)->next == NULL)
		error_handler(7, "add");

	n = (*stack)->n + (*stack)->next->n;
	pop_op(stack, line_number);
	(*stack)->n = n;
}
