#include "monty.h"

/**
 * swap_op - remove the first node in a stack_t doubly linked list
 * @stack: a pointer to the head of the list
 * @line_number: file line number opcode received from
 * Return: Nothing
 */
void swap_op(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	int n;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		error_handler(7, "swap");

	n = (*stack)->n;
	(*stack)->n = ((*stack)->next)->n;
	((*stack)->next)->n = n;
}
