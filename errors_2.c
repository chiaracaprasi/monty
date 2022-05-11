#include "monty.h"

/**
 * push_error - prints push error error message
 * @opcode: opcode passed as argument
 *
 * Return: Nothing
 */
void push_error(__attribute__((unused))char *opcode)
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
 * Return: Nothing
 */
void pop_error(__attribute__ ((unused)) char *opcode)
{
	dprintf(STDERR_FILENO, POP_FAIL, g_data.lineNum);
	free(*(g_data.buffer));
	fclose(g_data.montyFile);
	exit(EXIT_FAILURE);
}

/**
 * mod_error - prints error message
 * @opcode: opcode passed as argument
 *
 * Return: Nothing
 */
void mod_error(__attribute__ ((unused)) char *opcode)
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
