#include "monty.h"

/**
 * f_push - Add node to the stack
 * @head: Stack head
 * @line_number: line number
 *
 * Return: No return value
 */

void f_push(stack_t **head, unsigned int line_number)
{
	int num, j = 0, flag = 0;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			j++;
		for (; bus.arg[j] != '\0'; j++)
		{
			if (bus.arg[j] > '9' || bus.arg[j] < '0')
				flag = 1;
		}
		if (flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			fclose(bus.file);
			free(bus.content);
			free_stack(*head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	num = atoi(bus.arg);

	if (bus.lifi == 0)
		addnode(head, num);
	else
		addqueue(head, num);
}
