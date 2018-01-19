#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head;
struct node *tail;

void
push(int data)
{
    struct node *new_node =
                (struct node *)malloc(sizeof(struct node));

    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;

    struct node *h_temp = head;

    if (head == NULL)
    {
        head = new_node;
        tail = new_node;
    }
    else
    {
        while (h_temp->next)
        {
            h_temp = h_temp->next;
        }
        h_temp->next = new_node;
        new_node->prev = h_temp;
        tail = new_node;
    }
}

struct node *
pop(void)
{
    struct node *temp =tail;

    if (temp == NULL)
        return NULL;

    struct node *pop_node = temp;
    temp = temp->prev;
    temp->next = NULL;
    tail = temp;
    return pop_node;
}

void
display(void)
{
    struct node *temp = head;
    while(temp)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

void
init()
{
    head = NULL;
    tail = NULL;
}

int main()
{
    struct node *temp = NULL;
    init();
    push(10);
    push(11);
    push(12);
    push(13);
    push(14);
    printf("top %d\n", tail->data);
    display();
    temp = pop();
    printf("Node deleted with value %d\n", temp->data);
    free(temp);
    display();
    temp = pop();
    printf("Node deleted with value %d\n", temp->data);
    free(temp);
    display();
}
