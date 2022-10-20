#include "lists.h"

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: double pointer to head of list
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 */

int is_palindrome(listint_t **head)
{
    listint_t *temp;
    int i, j, len, *arr;

    if (head == NULL || *head == NULL)
        return (1);
    temp = *head;
    len = 0;

    while (temp != NULL)
    {
        temp = temp->next;
        len++;
    }

    arr = malloc(sizeof(int) * len);
    if (arr == NULL)
        return (0);

    temp = *head;

    for (i = 0; i < len; i++)
    {
        arr[i] = temp->n;
        temp = temp->next;
    }

    for (i = 0, j = len - 1; i < len / 2; i++, j--)
    {
        if (arr[i] != arr[j])
        {
            free(arr);
            return (0);
        }
    }

    free(arr);
    return (1);
}