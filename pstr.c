#include "monty.h"

/**
 * f_pstr - Prints the string starting at the top of the stack
 * @head: Stack head
 * @line_number: Line number
 *
 * Return: No return value
 */
void f_pstr(stack_t **head, unsigned int line_number)
{
    stack_t *current = *head;

    (void)line_number;

    while (current != NULL && current->n != 0 && current->n >= 0 && current->n <= 127)
    {
        putchar(current->n);
        current = current->next;
    }
    putchar('\n');
}

