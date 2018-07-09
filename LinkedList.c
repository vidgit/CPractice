#include <stdio.h>

struct Node
{
    int data;
    struct Node *next;
};

void add(struct Node **head, int data)
{

    if (*head == NULL)
    {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->next = NULL;
        *head = newNode;
        return;
    }

    if ((*head)->next == NULL)
    {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->next = NULL;
        (*head)->next = newNode;
        return;
    }

    add(&((*head)->next), data);
    return;
}

void removeNode(struct Node **head, int key)
{
    if (*head == NULL)
        return;

    if ((*head)->data == key)
    {
        struct Node *temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }

    if ((*head)->next == NULL)
        printf("Value not found!");
    else
        removeNode(&((*head)->next), key);
}

void printlist(struct Node *head)
{
    if (head != NULL)
    {
        printf("%d ", head->data);
        printlist(head->next);
    }
}

int main()
{
    struct Node *head = NULL;
    add(&head, 1);
    add(&head, 2);
    add(&head, 3);
    printlist(head);
    printf("\n");
    removeNode(&head, 3);
    printlist(head);
    return 0;
}