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

/**
 * sub_op - subs the first int from the next, held in a stack_t
 * doubly linked list
 * @stack: pointer to the head of the list
 * @line_number: line no\umber opcode was found in
 * Return: Nothing
 */
void sub_op(stack_t **stack, unsigned int line_number)
{
	int n;

	if (*stack == NULL || (*stack)->next == NULL)
		error_handler(7, "sub");

	n = (*stack)->next->n - (*stack)->n;
	pop_op(stack, line_number);
	(*stack)->n = n;
}

/**
 * div_op - subs the first int from the next, held in a stack_t
 * doubly linked list
 * @stack: pointer to the head of the list
 * @line_number: line no\umber opcode was found in
 * Return: Nothing
 */
void div_op(stack_t **stack, unsigned int line_number)
{
	int n;

	if ((*stack)->n == 0)
		error_handler(8, NULL);

	if (*stack == NULL || (*stack)->next == NULL)
		error_handler(7, "div");

	n = (*stack)->next->n / (*stack)->n;
	pop_op(stack, line_number);
	(*stack)->n = n;
}

/**
 * mod_op - subs the first int from the next, held in a stack_t
 * doubly linked list
 * @stack: pointer to the head of the list
 * @line_number: line no\umber opcode was found in
 * Return: Nothing
 */
void mod_op(stack_t **stack, unsigned int line_number)
{
	int n;

	if ((*stack)->n == 0)
		error_handler(8, NULL);

	if (*stack == NULL || (*stack)->next == NULL)
		error_handler(7, "mod");

	n = (*stack)->next->n % (*stack)->n;
	pop_op(stack, line_number);
	(*stack)->n = n;
}

/**
 * mul_op - subs the first int from the next, held in a stack_t
 * doubly linked list
 * @stack: pointer to the head of the list
 * @line_number: line no\umber opcode was found in
 * Return: Nothing
 */
void mul_op(stack_t **stack, unsigned int line_number)
{
	int n;

	if (*stack == NULL || (*stack)->next == NULL)
		error_handler(7, "mul");

	n = (*stack)->next->n * (*stack)->n;
	pop_op(stack, line_number);
	(*stack)->n = n;
}
