#include "monty.h"

/**
 * handle_errors - handles error
 * @errno: the error code to manage
 * @op_code: the operation code
 * @error_lin: the line on which the error occurred
 * @buff: the stored error buffer
 */

void handle_errors(int errno, char *op_code, unsigned int error_lin, char *buff)
{
	if (errno >= 100 && errno < 200)
		handle_cerror(errno, op_code, error_lin);
	else if (errno >= 200 && errno <= 210)
		handle_uerror(errno, error_lin);
	else if (errno >= 211 && errno <= 220)
		handle_more_uerror(errno, error_lin);
	else
		return;
	frees_stack();
	if (buff)
		free(buff);
	exit(EXIT_FAILURE);
}

/**
 * handle_cerror - handles common error
 * @errno: the error code to manage
 * @op_code: the operation code
 * @error_lin: the line on which the error occurre
 */

void handle_cerror(int errno, char *op_code, unsigned int error_lin)
{
	switch (errno)
	{
		case ERR_BAD_INST:
			fprintf(stderr, "L%d: unknown instruction %s\n", error_lin, op_code);
			break;
		case ERR_BAD_MALL:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		default:
			break;
	}
}

/**
 * handle_uerror - handles usage error
 * @errno: the error code to manage
 * @error_lin: the line on which the error occurre
 */

void handle_uerror(int errno, unsigned int error_lin)
{
	switch (errno)
	{
		case ERR_ARG_USG:
			fprintf(stderr, "USAGE monty file\n");
			break;
		case ERR_PUSH_USG:
			fprintf(stderr, "L%d: usage: push integer\n", error_lin);
			break;
		case ERR_PINT_USG:
			fprintf(stderr, "L%d: can't pint, stack empty\n", error_lin);
			break;
		case ERR_POP_USG:
			fprintf(stderr, "L%d: can't pop an empty stack\n", error_lin);
			break;
		case ERR_SWAP_USG:
			fprintf(stderr, "L%d: can't swap, stack too short\n", error_lin);
			break;
		case ERR_ADD_USG:
			fprintf(stderr, "L%d: can't _add_, stack too short\n", error_lin);
			break;
		case ERR_SUB_USG:
			fprintf(stderr, "L%d: can't _sub, stack too short\n", error_lin);
			break;
		case ERR_DIV_USG:
			fprintf(stderr, "L%d: can't div, stack too short\n", error_lin);
			break;
		case ERR_DIV_ZRO:
			fprintf(stderr, "L%d: division by zero\n", error_lin);
			break;
		case ERR_MUL_USG:
			fprintf(stderr, "L%d: can't mul, stack too short\n", error_lin);
			break;
		case ERR_MOD_USG:
			fprintf(stderr, "L%d: can't mod, stack too short\n", error_lin);
			break;
		default:
			break;
	}
}

/**
 * handle_more_uerror - handles more usage error
 * @errno: the error code to manage
 * @error_lin: the line on which the error occurre
 */

void handle_more_uerror(int errno, unsigned int error_lin)
{
	switch (errno)
	{
		case ERR_PCH_USG:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", error_lin);
			break;
		case ERR_PCH_EMP:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", error_lin);
			break;
		default:
			break;
	}
}
