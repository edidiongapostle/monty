#include "monty.h"

/**
 * f_div - Divides the second top element of the stack by the top element
 * @head: Stack head
 * @line_number: Line number
 *
 * Return: No return value
 */
void f_div(stack_t **head, unsigned int line_number)
{
    stack_t *first, *second;

    if (*head == NULL || (*head)->next == NULL)
    {
        fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    first = *head;
    second = (*head)->next;

    if (first->n == 0)
    {
        fprintf(stderr, "L%u: division by zero\n", line_number);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    second->n /= first->n;
    *head = second;
    second->prev = NULL;
    free(first);
}

