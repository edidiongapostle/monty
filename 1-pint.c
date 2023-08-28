#include "monty.h"

/**
 * pint - prints the value at the top of the stack
 * @stack: the given stack to print from
 * @line_data: the line with the error occurred
 */

void pint(stack_t **stack, unsigned int line_data)
{
	if (*stack == NULL)
		handle_errors(ERR_PINT_USG, NULL, line_data, NULL);
	printf("%d\n", (*stack)->n);
}
