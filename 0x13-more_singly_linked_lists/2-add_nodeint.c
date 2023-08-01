#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include "lists.h"

/**
 * add_nodeint - adds a new node at the beginning of a linked list
 * @head: pointer to the first node in the list
 * @p: data to insert in that new node
 *
 * Return: pointer to the new node, or NULL if it fails
 */
listint_t *add_nodeint(listint_t **head, const int p)
{
listint_t *new;

new = malloc(sizeof(listint_t));
if (!new)
return (NULL);

new->p = p;
new->next = *head;
*head = new;

return (new);
}

