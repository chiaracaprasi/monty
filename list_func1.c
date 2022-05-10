#inclide "monty.h"
/**
 * add_dnodeint - adds a new node at the beginning of list
 * @head: pointer to pointer to first node in list_t
 * @n: data to add
 * Return: address of the new element, or NULL if it failed
 */

dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *newNode = malloc(sizeof(dlistint_t));

	if (newNode == NULL)
		return (NULL);
	newNode->n = n;
	newNode->next = *head;
	newNode->prev = NULL;

	if (*head == NULL)
		newNode->next = NULL;
	else
		(*head)->prev = newNode;
	*head = newNode;
	return (newNode);
}

/**
 * add_dnodeint_end - adds a new node at the end of list
 * @head: pointer to pointer to first node in list_t
 * @n: data to add
 * Return: address of the new element, or NULL if it failed
 */

dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *temp = *head;
	dlistint_t *newNode = malloc(sizeof(dlistint_t));

	if (head == NULL)
		return (NULL);

	if (newNode == NULL)
		return (NULL);

	newNode->n = n;
	newNode->next = NULL;
	if (*head == NULL)
	{
		*head = newNode;
		newNode->prev = NULL;
		return (newNode);
	}
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = newNode;
		newNode->prev = temp;
	}
	return (newNode);
}

/**
 * dlistint_len - function that returns the number of elements in list
 * @h: list given
 *
 * Return: number of nodes
 */

size_t dlistint_len(const dlistint_t *h)
{
	int node = 0;

	if (h == NULL)
		return (0);
	while (h != NULL)
	{
		node++;
		h = h->next;
	}
	return (node);
}

/**
 * print_dlistint - function that prints all the elements of a dlist_t list.
 * @h: list given
 *
 * Return: number of nodes
 */

size_t print_dlistint(const dlistint_t *h)
{
	int node = 0;

	if (h == NULL)
		return (0);
	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
		node++;
	}
	return (node);
}
