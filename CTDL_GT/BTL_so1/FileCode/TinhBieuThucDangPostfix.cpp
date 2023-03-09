//Write a C program to evaluate the postfix expression using stack.
#include<stdio.h>
#include<ctype.h>

int stack[20];
int top = -1;

void push();
int pop();
void EvalPostFix();

//Them 1 phan tu vao stack.
void push(char x)
{
    stack[++top] = x;
}
//Lay 1 phan tu ra khoi stack.
int pop()
{
    return stack[top--];
}
//Ham EvalPostFix de tinh
void EvalPostFix(char exp[])
{
	char *e;
	int n1,n2,n3,num;
	e = exp;
    while(*e != NULL)
    {
        //Ham isdigit(): kiem tra ki tu co phai la ki tu so(0-9) hay khong.
        if(isdigit(*e))
        {
        //Neu kiem tra la 1 chu so, ta tru cho 48 de xac dinh no la so nguyen trong khoang(0-9)
        //Sau do push no vao Stack.
            num = *e - 48;
            push(num);
        }
        //Nguoc lai, ta kiem tra no la '+', '-', '*', '/'
        else
        {
            n1 = pop();
            n2 = pop();
            switch(*e)
            {
                case '+':
                {
                    n3 = n1 + n2;
                    break;
                }
                case '-':
                {
                    n3 = n2 - n1;
                    break;
                }
                case '*':
                {
                    n3 = n1 * n2;
                    break;
                }
                case '/':
                {
                    n3 = n2 / n1;
                    break;
                }
            }
            //Push(n3) vao Stack.
            push(n3);
        }
        e++;
    }
    //Pop toan bo Stack ra thi ta duoc ket qua.
    printf("\nThe result of expression: %s =  %d \n",exp,pop());
}
int main()
{
    char exp[20];
    printf("Enter the expression: \n");
    scanf("%s",exp);
    EvalPostFix(exp);
    return 0;
}
