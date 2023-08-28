#include "monty.h"

/**
 * push - _add_s a new node at the beginning of the stack
 * @stack: the given head pointer
 * @paline: the data to _add_
 *
 */

void push(stack_t **stack, unsigned int paline)
{
	stack_t *new_node = NULL;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		handle_errors(ERR_BAD_MALL, NULL, 0, NULL);

	new_node->n = paline;

	if (*stack)
	{
		new_node->next = *stack;
		new_node->prev = (*stack)->prev;
		(*stack)->prev = new_node;
		*stack = new_node;
		return;
	}

	new_node->next = *stack;
	new_node->prev = NULL;
	*stack = new_node;
}

/**
 * push_queue - _add_s a new node to the end of the stack
 * @stack: the given head pointer
 * @paline: the data to _add_
 *
 */

void push_queue(stack_t **stack, unsigned int paline)
{
	stack_t *new_node = NULL, *current_node = NULL;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		handle_errors(ERR_BAD_MALL, NULL, 0, NULL);

	new_node->n = paline;

	if (*stack)
	{
		current_node = *stack;
		while (current_node->next != NULL)
			current_node = current_node->next;

		new_node->next = NULL;
		new_node->prev = current_node;
		current_node->next = new_node;
		return;
	}

	new_node->next = *stack;
	new_node->prev = NULL;
	*stack = new_node;
}
