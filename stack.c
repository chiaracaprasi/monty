#include "monty.h"

/**
 * stack_builder - calls functions to add new node to the stack, adds int data
 * @n: the integer to be stored in the node
 * Return: 0 if successful, NULL if failed
 */
int stack_builder(int n)
{
	stack_t *new;

	if (g_data.mode == 0)
		new = push_node();
	else
		new = enqueue_node();

	if (new == NULL)
		return (-1);

	new->n = n;

	return (0);
}
/**
 * push_node - adds node to start of stack_t doubly linked list (circular)
 * Return: a pointer to the new node or NULL if failed
 */
stack_t *push_node(void)
{
	stack_t **head = g_data.head;
	stack_t *new;

	new = malloc(sizeof(*new));

	if (new == NULL)
		return (NULL);

	if (*head == NULL)
	{
		new->prev = NULL;
		new->next = NULL;
		*head = new;
		return (new);
	}

	if ((*head)->next == NULL)
	{
		new->prev = *head;
		new->next = *head;
		(*head)->prev = new;
		(*head) = new;
		return (new);
	}

	new->prev = (*head)->prev;
	new->next = *head;
	(*head)->prev = new;
	*head = new;
	return (new);
}

/**
 * enqueue_node - adds node to the end of a stack_t doubly
 * linked list (circular)
 * Return: a pointer to the new node or NULL if failed
 */
stack_t *enqueue_node(void)
{
	stack_t **head = g_data.head;
	stack_t *new;

	new = malloc(sizeof(*new));

	if (new == NULL)
		return (NULL);

	if (*head == NULL)
	{
		new->prev = NULL;
		new->next = NULL;
		*head = new;
		return (new);
	}

	if ((*head)->next == NULL)
	{
		new->prev = *head;
		new->next = NULL;
		(*head)->prev = new;
		(*head)->next = new;
		return (new);
	}

	new->prev = (*head)->prev;
	new->next = NULL;
	new->prev->next = new;
	(*head)->prev = new;
	return (new);
}

/**
 * delete_node - deletes a node from the start of a stack_t doubly linked
 * list (circular)
 * Return: Nothing
 */
void delete_node(void)
{
	return;
}

/**
 * free_stack - frees a stack_t doubly linked list
 * Return: Nothing
 */
void free_stack(void)
{
	stack_t *head = *(g_data.head);

	if (head == NULL)
		return;

	while (head->next != NULL)
	{
		head = head->next;
		free(head->prev);
	}

	free(head);
}
