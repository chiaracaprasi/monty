#include "monty.h"
void free_stack()
{
	stack_t *head = *(access.head);

	if (head == NULL)
		return;

	while (head->next != NULL)
	{
		head = head->next;
		free(head->prev);
	}

	free(head);
}
