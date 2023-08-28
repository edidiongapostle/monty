#include "monty.h"

/**
 * stack_push - adds a new node at the beginning of the stack
 * @head: the given head pointer
 * @data: the data to add
 */
void stack_push(stack_t **head, unsigned int data)
{
    stack_t *new_item = NULL;

    new_item = malloc(sizeof(stack_t));
    if (new_item == NULL)
        handle_error(ERR_BAD_MALL, NULL, 0, NULL);

    new_item->n = data;

    if (*head)
    {
        new_item->next = *head;
        new_item->prev = (*head)->prev;
        (*head)->prev = new_item;
        *head = new_item;
        return;
    }

    new_item->next = *head;
    new_item->prev = NULL;
    *head = new_item;
}

/**
 * queue_push - adds a new node to the end of the stack
 * @head: the given head pointer
 * @data: the data to add
 */
void queue_push(stack_t **head, unsigned int data)
{
    stack_t *new_item = NULL, *current_item = NULL;

    new_item = malloc(sizeof(stack_t));
    if (new_item == NULL)
        handle_error(ERR_BAD_MALL, NULL, 0, NULL);

    new_item->n = data;

    if (*head)
    {
        current_item = *head;
        while (current_item->next != NULL)
            current_item = current_item->next;

        new_item->next = NULL;
        new_item->prev = current_item;
        current_item->next = new_item;
        return;
    }

    new_item->next = *head;
    new_item->prev = NULL;
    *head = new_item;
}

