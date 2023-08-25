#include "monty.h"

/**
 * f_swap - Swaps the top two elements of the stack
 * @head: Stack head
 * @line_number: Line number
 *
 * Return: No return value
 */

void f_swap(stack_t **head, unsigned int line_number)
{
	stack_t *first, *second;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	first = *head;
	second = (*head)->next;

	first->next = second->next;
	if (second->next != NULL)
		second->next->prev = first;

	second->prev = NULL;
	second->next = first;

	first->prev = second;
	*head = second;
}
