#include "monty.h"

/**
 * error_handler - reads a line from a given file stream
 * @error_code: error code given as argument
 * Return: void
 */

void error_handler(int error_code, char *opcode)
{
	int idx = 0;
	error_selector error_selector[] = {
		{1, usage_error},
		{2, malloc_error},
		{3, unknown_op},
		{4, push_op},
		{5, pint_op},
		{6, pop_op},
		{7, short_error},
		{8, mod_op},
		{NULL, NULL}
	};

	while (error_selector[idx].err_num != NULL)
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
void usage_error( __attribute__ ((unused)) char *opcode)
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
 * unknown_op - handles error for uknown opcode
 * @opcode: opcode passed as argument
 *
 * Return: Nothing
 */
void unknown_op(char *opcode)
{
	dprintf(STDERR_FILENO, UNKNOWN, g_data.lineNum);
	free_stack();
	free(*(g_data.buffer));
	fclose(g_data.montyFile);
	exit(EXIT_FAILURE);
}

/**
 * push_error - prints push error error message
 * @opcode: opcode passed as argument
 *
 * Return: Nothing
 */
void push_error(__attribute__ ((unused)) char *opcode)
{
	dprintf(STDERR_FILENO, PUSH_FAIL, g_data.lineNum);
	free_stack();
	free(*(g_data.buffer));
	fclose(g_data.montyFile);
	exit(EXIT_FAILURE);
}

/**
 * pint_error - prints pint error message
 * @opcode: opcode passed as argument
 *
 * Return: Nothing
 */
void pint_error(__attribute__ ((unused)) char *opcode)
{
	dprintf(STDERR_FILENO, PINT_FAIL, g_data.lineNum);
	free_stack();
	free(*(g_data.buffer));
	fclose(g_data.montyFile);
	exit(EXIT_FAILURE);
}

/**
 * pop_error - prints pop error error message
 * @opcode: opcode passed as argument
 *
 * Return: EXIT_FAILURE
 */
int pop_error(__attribute__ ((unused)) char *opcode)
{
	dprintf(STDERR_FILENO, POP_FAIL, g_data.lineNum);
	free(*(g_data.buffer));
	fclose(g_data.montyFile);
	exit(EXIT_FAILURE);
}

/**
 * mod_op - prints error message
 * @opcode: opcode passed as argument
 *
 * Return: Nothing
 */
void mod_op(__attribute__ ((unused)) char *opcode)
{
	dprintf(STDERR_FILENO, MOD_0, g_data.lineNum);
	free_stack();
	free(*(g_data.buffer));
	fclose(g_data.montyFile);
	exit(EXIT_FAILURE);
}

/**
 * short_error - prints error when stack too short for op
 * @opcode: opcode passed as argument
 *
 * Return: Nothing
 */

void short_error(char *opcode)
{
	dprintf(STDERR_FILENO, OP_FAIL, g_data.lineNum, opcode);
	free_stack();
	free(*(g_data.buffer));
	fclose(g_data.montyFile);
	exit(EXIT_FAILURE);
}
