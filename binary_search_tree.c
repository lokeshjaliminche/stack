#include <stdio.h>
#include <stdlib.h>
/*create a node which holds address of a btree node.*/
struct stack_node
{
    struct node *bst_node;
    struct stack_node *prev;
    struct stack_node *next;
};

/* define btree node */
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

/* declare global root node for btree */
struct node *root;

/*global pointer to perform push and pop in stack*/
struct stack_node *head;
struct stack_node *tail;

void
push(struct node *bst_node)
{
    struct stack_node *new_node =
                (struct stack_node *)malloc(sizeof(struct stack_node));

    new_node->bst_node = bst_node;
    new_node->next = NULL;
    new_node->prev = NULL;

    struct stack_node *h_temp = head;

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

struct stack_node *
pop(void)
{
    struct stack_node *temp =tail;

    if (temp == NULL)
        return NULL;

    struct stack_node *pop_node = temp;
    if (temp->prev)
    {
        temp = temp->prev;
        temp->next = NULL;
        tail = temp;
        if (tail == NULL)
            head == NULL;
        return pop_node;
    }
    else
    {
        head = NULL;
        tail = NULL;
        return temp;
    }
}

void
display_stack(void)
{
    struct stack_node *temp = head;
    while(temp)
    {
        printf("%d\n", temp->bst_node->data);
        temp = temp->next;
    }
}

/* Initialize stack */
void
init_stack()
{
    head = NULL;
    tail = NULL;
}

/* Initialize bst */
void
init_bst()
{
    root = NULL;
}

/* do global initialization */
void
init()
{
    init_bst();
}


void
insert_bst(int data)
{
    struct node *new_node =
                (struct node *)malloc(sizeof(struct node));

    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;

    struct node *temp = root;

    if (root == NULL)
    {
        root = new_node;
    }
    else
    {
        struct node *prev = NULL;
        while (1)
        {
            if (data < temp->data)
            {
                prev = temp;
                temp = temp->left;
                if (temp == NULL)
                {
                    prev->left = new_node;
                    break;
                }
            }
            else
            {
                prev = temp;
                temp = temp->right;
                if (temp == NULL)
                {
                    prev->right = new_node;
                    break;
                }
            }

        }
    }
}

void
display_bst_inorder(void)
{
    struct node *current = root;
    init_stack();

    if (current == NULL)
        printf("tree is empty\n");
    else
    {
       while(1)
       {
           if (current)
           {
                push(current);
                current = current->left;
           }
           else
           {
               if (head != NULL)
               {
                    struct stack_node *temp = NULL;
                    temp = pop();
                    current = temp->bst_node;
                    printf("%d\n", current->data);
                    current = current->right;
               }
               else
               {
                    break;
               }
           }
       }
    }

}

int main()
{
    struct node *temp = NULL;
    init();
    insert_bst(6);
    insert_bst(11);
    insert_bst(8);
    insert_bst(7);
    insert_bst(4);
    insert_bst(2);
    insert_bst(1);
    display_bst_inorder();
}
