#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

void printL(struct node *head)
{
    printf("\n");
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
}

struct node *addAtBeg(struct node *head, int data)
{
    struct node *temp = malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;

    temp->next = head;
    head->prev = temp;
    head = temp;
    return head;
}

struct node *addToempty(struct node *head, int data)
{
    head = malloc(sizeof(struct node));
    head->data = data;
    head->prev = NULL;
    head->next = NULL;
    return head;
}

void addAtEnd(struct node *head, int data)
{
    struct node *temp, *tp;
    temp = malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;
    tp = head;
    while (tp->next != NULL)
        tp = tp->next;
    tp->next = temp;
    temp->prev = tp;
}

void addAfter(struct node *head, int data, int pos)
{
    struct node *newP = NULL;
    struct node *temp = head;
    struct node *temp2 = NULL;
    newP = addToempty(newP, data);
    while (pos != 1)
    {
        temp = temp->next;
        pos--;
    }
    if (temp->next == NULL)
    {
        temp->next = newP;
        newP->prev = temp;
    }
    else
    {
        temp2 = temp->next;
        temp->next = newP;
        temp2->prev = newP;
        newP->next = temp2;
        newP->prev = temp;
    }
}

struct node *addB4(struct node *head, int data, int p)
{
    struct node *newP = NULL;
    struct node *temp = head;
    struct node *temp2 = NULL;
    newP = addToempty(newP, data);
    if (p == 1)
    {
        head = addAtBeg(head, data);
    }
    else
    {
        int pos = p;
        while (pos > 2)
        {
            temp = temp->next;
            pos--;
        }

        temp2 = temp->next;
        temp->next = newP;
        if (temp2 != NULL)
            temp2->prev = newP;
        newP->next = temp2;
        newP->prev = temp;
    }
    return head;
}

struct node *delF(struct node *head)
{
    head = head->next;
    free(head->prev);
    head->prev = NULL;
    return head;
}

void delL(struct node *head)
{
    struct node *temp = head, *temp2;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp2 = temp->prev;
    temp2->next = NULL;
    free(temp);
    temp = NULL;
}

struct node *delInter(struct node *head, int p)
{
    struct node *temp = head;
    struct node *temp2 = NULL;
    if (p == 1)
    {
        head = delF(head);
        return head;
    }
    while (p > 1)
    {
        temp = temp->next;
        p--;
    }
    if (temp->next == NULL)
        delL(head);
    else
    {
        temp2 = temp->prev;
        temp2->next = temp->next;
        temp->next->prev = temp2;
        free(temp);
        temp = NULL;
    }
    return head;
}

int main()
{
    struct node *head = NULL;
    head = addToempty(head, 89);

    head = addAtBeg(head, 90);
    head = addAtBeg(head, 12);
    head = addAtBeg(head, 120);
    head = addAtBeg(head, 123);

    printL(head);
    addAtEnd(head, 9);
    addAtEnd(head, 123);

    printL(head);
    head = delInter(head, 3);
    printL(head);
    return 0;
