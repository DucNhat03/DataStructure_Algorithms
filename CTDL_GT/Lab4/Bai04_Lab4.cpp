
#include<stdio.h>
int stk[100];
int size = 100;
int ptr = -1;

void push(int x)
{
    if(ptr==size-1)
    {
        printf("Stack tran \n");
    }
    else
    {
        ++ptr;
        stk[ptr] = x;
    }
}

int top()
{
    if(ptr==-1)
    {
        printf("UnderFlow \n");
        return -1;
    }
    else{
        return stk[ptr];
    }
}

void pop()
{

    if(ptr==-1)
    {
        printf("UnderFlow \n");
    }
    else
    {
        --ptr;
    }
}

int isempty()
{
    if(ptr==-1)
        return 1;
    else
        return 0;
}
int main()
{
    int i, n;

    printf("Enter a number: ");
    scanf("%d", &n);

    push(1);
    for(i=2;i<=n;++i)
    {
        push(top() * i);
    }
    printf("%d Factorial= %d", n, top());
    return 0;
}
