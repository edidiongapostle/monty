#include "monty.h"

/**
 * mul - multiply the second top element of the stack with the top element of
 * the stack
 * @stack: the stack to work with
 * @line_data: where the error occured
 */

void mul(stack_t **stack, unsigned int line_data)
{
	stack_t *temp = *stack;
	unsigned int len = 0, a = 0, b = 0;

	len = count_stack(*stack);

	if (len < 2)
		handle_errors(ERR_MUL_USG, NULL, line_data, NULL);
	a = temp->n;
	b = temp->next->n;
	temp->next->n = b * a;
	*stack = temp->next;
	free(temp);
}
