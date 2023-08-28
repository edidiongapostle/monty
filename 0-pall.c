#include "monty.h"

/**
 * pall - prints all the elements on the stack
 * @stack: the given head pointer
 * @line_data: The line on which the error occurred
 *
 */
void pall(stack_t **stack, unsigned int line_data)
{
	stack_t *start = NULL;
	(void) line_data;

	if (*stack)
	{
		start = *stack;
		while (start != NULL)
		{
			printf("%d\n", start->n);
			start = start->next;
		}
	}
}
