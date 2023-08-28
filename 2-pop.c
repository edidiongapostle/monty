#include "monty.h"

/**
 * pop - removes the top element of the stack
 * @stack: the stack to operate on
 * @line_data: the line where an error occurred
 */

void pop(stack_t **stack, unsigned int line_data)
{
	stack_t *start = NULL, *temp = NULL;

	if (*stack == NULL)
		handle_errors(ERR_POP_USG, NULL, line_data, NULL);

	start = temp = *stack;

	if (start->next)
	{
		start = start->next;
		start->prev = temp->prev;
		*stack = start;
	}
	else
		*stack = NULL;
	free(temp);
}
