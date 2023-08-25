#include "monty.h"

/**
 * f_pchar - Prints the char at the top of the stack
 * @head: Stack head
 * @line_number: Line number
 *
 * Return: No return value
 */
void f_pchar(stack_t **head, unsigned int line_number)
{
    stack_t *top;

    if (*head == NULL)
    {
        fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    top = *head;

    if (top->n < 0 || top->n > 127)
    {
        fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    putchar(top->n);
    putchar('\n');
}

