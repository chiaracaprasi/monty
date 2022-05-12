#include "monty.h"

/**
 * pchar_op - prints the char value on top of stack followed by \n
 * @stack: pointer to pointer to first node in list
 * @line_number: number of line
 * Return: void
 */

void pchar_op(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	if (*stack == NULL || stack == NULL)
		error_handler(10, NULL);
	if ((*stack)->n < 0 || (*stack)->n > 127)
		error_handler(9, NULL);
	printf("%c\n", (*stack)->n);
}


/**
 * pchar_value_error - prints value of range error message
 * @opcode: opcode passed as argument
 *
 * Return: Nothing
 */
void pchar_value_error(__attribute__ ((unused)) char *opcode)
{
	dprintf(STDERR_FILENO, PCHAR_VALUE, g_data.lineNum);
	free_stack();
	free(*(g_data.buffer));
	fclose(g_data.montyFile);
	exit(EXIT_FAILURE);
}

/**
 * pchar_empty_error - prints value of range error message
 * @opcode: opcode passed as argument
 *
 * Return: Nothing
 */
void pchar_empty_error(__attribute__ ((unused)) char *opcode)
{
	dprintf(STDERR_FILENO, PCHAR_EMPTY, g_data.lineNum);
	free_stack();
	free(*(g_data.buffer));
	fclose(g_data.montyFile);
	exit(EXIT_FAILURE);
}
