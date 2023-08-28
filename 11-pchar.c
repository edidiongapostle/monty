#include "monty.h"

/**
 * pchar - prints the char at the top of the stack, followed by a new line
 * @stack: the stack to operate on
 * @line_data: the line where an error occurred
 */

void pchar(stack_t **stack, unsigned int line_data)
{
	stack_t *start = NULL;

	if (*stack == NULL)
		handle_errors(ERR_PCH_EMP, NULL, line_data, NULL);

	start = *stack;

	if (start->n >= 0 && start->n <= 127)
		printf("%c\n", start->n);
	else
		handle_errors(ERR_PCH_USG, NULL, line_data, NULL);
}
