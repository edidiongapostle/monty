#include "monty.h"

/**
 * f_rotl - Rotates the stack to the top
 * @head: Stack head
 * @line_number: Line number
 *
 * Return: No return value
 */
void f_rotl(stack_t **head, unsigned int line_number)
{
    stack_t *first, *last;

    (void)line_number;

    if (*head == NULL || (*head)->next == NULL)
        return;

    first = *head;
    last = *head;

    while (last->next != NULL)
        last = last->next;

    *head = first->next;
    first->next->prev = NULL;

    last->next = first;
    first->prev = last;
    first->next = NULL;
}

