// Write a c program to convert infix expression into postfix expression using Stack.
#include<stdio.h>
#include<ctype.h>

char stack[100];

int top = -1;
//Them 1 phan tu vao stack.
void push(char x)
{
    stack[++top] = x;
}
//Lay 1 phan tu ra khoi stack.
char pop()
{
    if(top == -1)
        return -1;
    else
        return stack[top--];
}
//kiểm tra độ ưu tiên các toán tử.
int priority(char x)
{
    if(x == '(')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
    return 0;
}
//Code xu li chuyen bieu thuc o dang Infix sang Postfix.
void chuyenInfixSangPostfix(char exp[]){
    char *e, x;
    e = exp;
    while(*e != NULL)
    {
        //isalnum: kiểm tra xem kí tự truyền vào có phải là kí tự - số hay không.
        if(isalnum(*e))
            printf("%c ",*e);
        else if(*e == '(')
            push(*e);
        // Neu phan tu e truyen vao la dau ')', ta se pop cac phan tu trong Stack den khi gap dau '('
        else if(*e == ')')
        {
            while((x = pop()) != '(')
                printf("%c ", x);
        }
         /*
            -Neu do uu tien tai vi tri stack[top] >= do uu tien cua gia tri nhan vao.
            Ta lay ra phan tu stack[top].
            - Nguoc lai, ta push no vao Stack.
        */
        else
        {
            while(priority(stack[top]) >= priority(*e))
                printf("%c ",pop());
                push(*e);
        }
        e++;
    }
        // Lay lan luot con gia tri con lai trong Stack ra.
    while(top != -1)
    {
        printf("%c ",pop());
    }
}
int main()
{
    char exp[100];
    char *e, x;
    printf("Nhap bieu thuc dang infix: \n");
    scanf("%s",&exp);
    printf("\nBieu thuc chuyen sang dang postfix: \n");
    chuyenInfixSangPostfix(exp);

    return 0;
}


