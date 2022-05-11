#include "monty.h"

/* struct to be moved to header file */
typedef struct error_selector
{
	int err_num;
	void (*f)(char *opcode);
} error_selector;

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
		{2, open_file_error },
		{3, unknown_op_error},
		{4, malloc_error },
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
 *
 * Return: EXIT_FAILURE
 */
int usage_error( __attribute__ ((unused)) char *opcode)
{
	dprintf(STDERR_FILENO, USAGE);
	exit(EXIT_FAILURE);

}

/**
 * malloc_error - prints malloc error message
 *
 * Return: EXIT_FAILURE
 */
int malloc_error(__attribute__ ((unused)) char *opcode)
{
	dprintf(STDERR_FILENO, MALLOC_FAIL);
	free_stack();
	free(g_data.(*buffer));   /* not 100% on that syntax */
	fclose(g_data.montyFile);
	exit(EXIT_FAILURE);
}



/**
 * unknown_op_error - prints unknown operation error message
 *
 * Return: EXIT_FAILURE
 */
/*
int unknown_op_error()
{
	dprintf(STDERR_FILENO, UNKNOWN);
	free_stack();
	free(g_data.(*buffer));
	fclose(g_data.montyFile);
	exit(EXIT_FAILURE);
}
*/



/* move to main.c
/**
 *open_file_error - prints file cannot be read error message
 *
 * Return: EXIT_FAILURE
 *
int open_file_error(char *opcode)
{
	dprintf(STDERR_FILENO, OPEN_ERR);
	exit(EXIT_FAILURE);
}
*/
