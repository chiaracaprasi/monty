#ifndef _MONTY_H_
#define _MONTY_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

/**
 * struct global_s - collection of globally needed variables
 * @head: a pointer to the head of the stack
 * @lineNum: line number from bytecode file;
 * @mode: indicates stack or queue mode, 1 for stack or 0 for queue
 * @montyFile: a pointer to the open file
 * @buffer: a pointer to the getline buffer
 *
 * Description: pointer to stack and line number of file at FILE *
 * globally available
 */
typedef struct global_s
{
	struct stack_s **head;
	unsigned int lineNum;
	int mode;
	FILE *montyFile;
	char **buffer;
} global_t;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

typedef stack_t dlistint_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct error_selector - error code and its function
 * @err_num: the error number
 * @f: function to handle the error message
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct error_selector
{
	int err_num;
	void (*f)(char *opcode);
} error_selector;

extern global_t g_data;

/* macros used for error messages */
#define USAGE "USAGE: monty file\n"
#define OPEN_ERR "Error: Can't open file %s\n"
#define UNKNOWN "L%u: unknown instruction %s\n"
#define MALLOC_FAIL "Error: malloc failed\n"
#define PUSH_FAIL "L%u: usage: push integer\n"
#define PINT_FAIL "L%u: can't pint, stack empty\n"
#define POP_FAIL "L%u: can't pop an empty stack\n"
#define MOD_0 "L%u: division by zero\n"
#define OP_FAIL "L%u: can't %s, stack too short\n"
#define PCHAR_VALUE "L%u: can't pchar, value out of range\n"
#define PCHAR_EMPTY "L%u: can't pchar, stack empty\n"

int get_monty(char **buffer, size_t *read, FILE *file);
void tokenise(char *bufferLine);
int token_check(char *token);
void stack_builder(int n);
void get_func(char *opCode);
stack_t *push_node(void);
stack_t *enqueue_node(void);
void free_stack(void);
void pall_op(stack_t **stack, unsigned int line_number);
void pint_op(stack_t **stack, unsigned int line_number);
void pop_op(stack_t **stack, unsigned int line_number);
void swap_op(stack_t **stack, unsigned int line_number);
void add_op(stack_t **stack, unsigned int line_number);
void sub_op(stack_t **stack, unsigned int line_number);
void div_op(stack_t **stack, unsigned int line_number);
void mul_op(stack_t **stack, unsigned int line_number);
void mod_op(stack_t **stack, unsigned int line_number);
void pchar_op(stack_t **stack, unsigned int line_number);
void pstr_op(stack_t **stack, unsigned int line_number);
void rotl_op(stack_t **stack, unsigned int line_number);
void rotr_op(stack_t **stack, unsigned int line_number);
void error_handler(int error_code, char *opcode);
void usage_error(char *opcode);
void malloc_error(char *opcode);
void unknown_op_error(char *opcode);
void push_error(char *opcode);
void pint_error(char *opcode);
void pop_error(char *opcode);
void short_error(char *opcode);
void mod_error(char *opcode);
void pchar_value_error(__attribute__ ((unused)) char *opcode);
void pchar_empty_error(__attribute__ ((unused)) char *opcode);

#endif /* _MONTY_H_ */
