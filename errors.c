#include "monty.h"

/**
 * error_handler - reads a line from a given file stream
 * @error_code: error code given as argument
 * @opcode: a string containing opcode passed in
 * Return: void
 */

void error_handler(int error_code, char *opcode)
{
	int idx = 0;
	error_selector error_selector[] = {
		{1, usage_error},
		{2, malloc_error},
		{3, unknown_op_error},
		{4, push_error},
		{5, pint_error},
		{6, pop_error},
		{7, short_error},
		{8, mod_error},
		{0, NULL}
	};

	while (error_selector[idx].err_num != 0)
	{
		if (error_selector[idx].err_num == error_code)
		{
			error_selector[idx].f(opcode);
		}
		idx++;
	}
}

/**
 * usage_error - prints usage error message
 * @opcode: opcode passed as argument
 *
 * Return: Nothing
 */
void usage_error(__attribute__((unused)) char *opcode)
{
	dprintf(STDERR_FILENO, USAGE);
	exit(EXIT_FAILURE);
}

/**
 * malloc_error - prints malloc error message
 * @opcode: opcode passed as argument
 *
 * Return: Nothing
 */
void malloc_error(__attribute__ ((unused)) char *opcode)
{
	dprintf(STDERR_FILENO, MALLOC_FAIL);
	free_stack();
	free(*(g_data.buffer));
	fclose(g_data.montyFile);
	exit(EXIT_FAILURE);
}

/**
 * unknown_op_error - handles error for uknown opcode
 * @opcode: opcode passed as argument
 *
 * Return: Nothing
 */
void unknown_op_error(char *opcode)
{
	dprintf(STDERR_FILENO, UNKNOWN, g_data.lineNum, opcode);
	free_stack();
	free(*(g_data.buffer));
	fclose(g_data.montyFile);
	exit(EXIT_FAILURE);
}
