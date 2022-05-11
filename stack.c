#include "monty.h"

int stack_builder(int n)
{
	stack_t *new;

	if (access.mode == 0)
		new = push_node();
	else
		new = enqueue_node();

	if (new == NULL)
		return (-1);

	new->n = n;

	return (0);
}

stack_t *push_node()
{
	stack_t **head = access.head;
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

stack_t *enqueue_node()
{
	stack_t **head = access.head;
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

void delete_node();
{
	return;
}

void free_stack();
{
	return;
}
