#include "monty.h"

/**
 * f_rotr - Rotates the stack to the bottom
 * @head: Stack head
 * @line_number: Line number
 *
 * Return: No return value
 */
void f_rotr(stack_t **head, unsigned int line_number)
{
    stack_t *last, *secondLast;

    (void)line_number;

    if (*head == NULL || (*head)->next == NULL)
        return;

    last = *head;
    secondLast = *head;

    while (last->next != NULL)
    {
        secondLast = last;
        last = last->next;
    }

    secondLast->next = NULL;
    last->prev = NULL;

    last->next = *head;
    (*head)->prev = last;

    *head = last;
}

