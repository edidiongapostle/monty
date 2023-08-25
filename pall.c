#include "monty.h"

/**
 * f_pall - Prints the stack
 * @head: Stack head
 * @line_number: Line number (not used)
 *
 * Return: No return value
 */

void f_pall(stack_t **head, unsigned int line_number)
{
	stack_t *current_node;
	(void)line_number;

	current_node = *head;

	if (current_node == NULL)
		return;

	while (current_node)
	{
		printf("%d\n", current_node->n);
		current_node = current_node->next;
	}
}
