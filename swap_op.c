#include "monty.h"

/**
 * swap_op - remove the first node in a stack_t doubly linked list
 * @stack: a pointer to the head of the list
 * @line_number: file line number opcode received from
 * Return: Nothing
 */
void swap_op(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *hold;

	if (*stack == NULL || (*stack)->next == NULL)
		error_handler(7, "swap");

	hold = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	hold->prev = *stack;

	if ((*stack)->next == NULL)
	{
		hold->next = NULL;
	}
	else
	{
		hold->next = (*stack)->next;
		(*stack)->next->prev = hold;
	}

	(*stack)->next = hold;
}
