#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

typedef struct stack_s
{
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;

typedef struct bus_s
{
    char *arg;
    FILE *file;
    char *content;
    int lifi;
} bus_t;

extern bus_t bus;

typedef struct instruction_s
{
    char *opcode;
    void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

char *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
ssize_t getstdin(char **lineptr, int file);
char *clean_line(char *content);

void push(stack_t **stack, unsigned int param);
void push_queue(stack_t **stack, unsigned int param);

void print_all(stack_t **head, unsigned int line_num); // Adjusted prototype

void pop(stack_t **head, unsigned int line_num);
void swap(stack_t **head, unsigned int line_num);
void add(stack_t **head, unsigned int line_num);

void nop(stack_t **head, unsigned int line_num);
void subtract(stack_t **head, unsigned int line_num);
void divide(stack_t **head, unsigned int line_num);
void multiply(stack_t **head, unsigned int line_num);
void modulo(stack_t **head, unsigned int line_num);

void print_char(stack_t **head, unsigned int line_num);
void print_str(stack_t **head, unsigned int line_num);
void rotate_left(stack_t **head, unsigned int line_num);
void rotate_right(stack_t **head, unsigned int line_num);

void add_node(stack_t **head, int n);
void add_to_queue(stack_t **head, int n);

void set_queue(stack_t **head, unsigned int line_num);
void set_stack(stack_t **head, unsigned int line_num);

#endif

