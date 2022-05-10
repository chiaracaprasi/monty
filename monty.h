#ifndef _MONTY_H_
#define _MONTY_H_

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * global_s - collection of globally needed variables
 * @head: a pointer to the head of the stack
 * @pushArg: int to be pushed onto the stack;
 * @lineNum: line number from bytecode file;
 * @fifo: indicates stack or queue mode, 1 for stack or 0 for queue
 */
typedef struct global_s
{
	struct stack_s **head;
	int pushArg;
	unsigned int lineNum;
	int mode;
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

extern global_t access;


int process(char *bufferLine);
void push_op(stack_t **stack, unsigned int line_number);
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

#endif /* _MONTY_H_ */
