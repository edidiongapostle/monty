#include "monty.h"

/**
 * handle_exec_ - manages the operation on the stack
 * @op_code: the operation code
 * @op_paline: the palineeter of the instruction
 * @error_lin: the line at which error occurred
 * @m: the method to be used for the operation
 *
 * Return: 0 if the operation was executed correctly or errcode if it failed
 */

int handle_exec_(char *op_code, char *op_paline, unsigned int error_lin, int m)
{
	int op_status = 0;
	void (*op_func)(stack_t **, unsigned int);

	if (strcmp(op_code, "stack") == 0)
		return (METH_STACK);
	if (strcmp(op_code, "queue") == 0)
		return (METH_QUEUE);

	op_func = pick_func(op_code);

	if (op_func)
	{
		if (strcmp(op_code, "push") == 0)
		{
			op_status = check_push_paline(op_paline);
			if (op_status == ERR_PUSH_USG)
				return (ERR_PUSH_USG);

			if (m != 0 && m == METH_QUEUE)
				op_func = pick_func("push_queue");

			op_func(&head, atoi(op_paline));
		}
		else
			op_func(&head, error_lin);
		return (m);
	}
	return (ERR_BAD_INST);
}
