#include "monty.h"

/**
 * rotl - swap the top element with last element
 * @stack: the stack to work with
 * @line_data: where the error occured
 */

void rotl(stack_t **stack, unsigned int line_data)
{
	stack_t *start = *stack;
	unsigned int temp = 0;
	(void) line_data;

	if (start && start->next)
	{
		while (start->next != NULL)
		{
			temp = start->n;
			start->n = start->next->n;
			start->next->n = temp;
			start = start->next;
		}
	}
}
