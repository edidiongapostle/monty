#include "monty.h"

/**
 * print_all - prints all the elements on the stack
 * @head: the given head pointer
 * @line_num: The line on which the error occurred
 */
void print_all(stack_t **head, unsigned int line_num)
{
    stack_t *current = NULL;
    (void) line_num;

    if (*head)
    {
        current = *head;
        while (current != NULL)
        {
            printf("%d\n", current->n);
            current = current->next;
        }
    }
}

