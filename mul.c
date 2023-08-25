#include "monty.h"

/**
 * f_mul - Multiplies the second top element of the stack with the top element
 * @head: Stack head
 * @line_number: Line number
 *
 * Return: No return value
 */
void f_mul(stack_t **head, unsigned int line_number)
{
    stack_t *first, *second;

    if (*head == NULL || (*head)->next == NULL)
    {
        fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    first = *head;
    second = (*head)->next;

    second->n *= first->n;
    *head = second;
    second->prev = NULL;
    free(first);
}

