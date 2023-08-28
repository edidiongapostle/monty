#include "monty.h"

/**
 * swap - swap the top two element
 * @stack: the stack to work with
 * @line_data: where the error occured
 */

void swap(stack_t **stack, unsigned int line_data)
{
	unsigned int len = 0, temp = 0;

	len = count_stack(*stack);

	if (len < 2)
		handle_errors(ERR_SWAP_USG, NULL, line_data, NULL);

	if (*stack)
	{
		temp = (*stack)->n;
		(*stack)->n = (*stack)->next->n;
		(*stack)->next->n = temp;
	}
}
