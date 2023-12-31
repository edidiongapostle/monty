#ifndef _MONTY_H
#define _MONTY_H
#define _POSIX_C_SOURCE 200809L
/* Constants */
#define VALID_paline 0
#define SUCSS_OP 0
#define MIN_ARGS 2
#define METH_STACK 300
#define METH_QUEUE 301

/* Error Constants */
#define ERR_BAD_INST 100
#define ERR_BAD_MALL 101
#define ERR_INVLD_paline 102

/* Usage Errors Constants */
#define ERR_ARG_USG 200
#define ERR_PUSH_USG 201
#define ERR_PINT_USG 202
#define ERR_POP_USG 203
#define ERR_SWAP_USG 204
#define ERR_ADD_USG 205
#define ERR_SUB_USG 206
#define ERR_DIV_USG 207
#define ERR_DIV_ZRO 208
#define ERR_MUL_USG 209
#define ERR_MOD_USG 210
#define ERR_PCH_USG 211
#define ERR_PCH_EMP 212

/* header files */
#include <ctype.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;


/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_data);
} instruction_t;

/* global variable */
extern stack_t *head;

void check_argc(int argc);
int check_digits(char *s);
int check_push_paline(char *paline);
void check_access_rights(char *filename);
unsigned int count_stack(stack_t *h);
void frees_stack(void);
void handle_uerror(int errno, unsigned int error_lin);
void handle_more_uerror(int errno, unsigned int error_lin);
void handle_cerror(int errno, char *op_code, unsigned int error_lin);
void handle_errors(int errno, char *op_code, unsigned int error_lin, char *buff);
int handle_exec_(char *op_code, char *op_paline, unsigned int error_lin, int m);
FILE *open_file(char *filename);
void (*pick_func(char *s))(stack_t **, unsigned int);
void push(stack_t **stack, unsigned int paline);
void push_queue(stack_t **stack, unsigned int paline);
void pall(stack_t **stack, unsigned int line_data);
void pint(stack_t **stack, unsigned int line_data);
void pop(stack_t **stack, unsigned int line_data);
void swap(stack_t **stack, unsigned int line_data);
void _add_(stack_t **stack, unsigned int line_data);
void nop(stack_t **stack, unsigned int line_data);
void _sub(stack_t **stack, unsigned int line_data);
void _div_(stack_t **stack, unsigned int line_data);
void mul(stack_t **stack, unsigned int line_data);
void _mod(stack_t **stack, unsigned int line_data);
void pchar(stack_t **stack, unsigned int line_data);
void pstr(stack_t **stack, unsigned int line_data);
void rotl(stack_t **stack, unsigned int line_data);
void rotr(stack_t **stack, unsigned int line_data);
#endif /* _MONTY_H */
