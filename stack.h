#define MAX 50

struct stack
{
    int arr[MAX];
    int top;
};

void push(int num);

int pop(void);

void display(void);
