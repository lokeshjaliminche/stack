#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

struct stack s;

void init()
{
    s.top = -1;
}

void push(int num)
{
    if (s.top == MAX-1)
    {
        printf("stack is full\n");
    }
    else
    {
        s.top = s.top + 1;
        s.arr[s.top] = num;
    }
}

int pop(void)
{
    int num;
    if (s.top == -1)
    {
        printf("stack is empty\n");
        return 0;
    }

    num = s.arr[s.top];
    s.top = s.top - 1;
    return num;
}

void display(void)
{
    int count = s.top;
    for (int i = 0; i <= count; i++)
    {
        printf("%d\n", s.arr[i]);
    }
}

int main()
{
    init();
    push(1);
    push(2);
    push(3);
    push(4);
    pop();
    display();
    push(5);
    display();
}
