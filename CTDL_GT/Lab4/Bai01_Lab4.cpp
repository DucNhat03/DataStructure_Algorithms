/* Viet chuong thao tac voi STACK su dung mang. */
#include <stdio.h>
#include <conio.h>
#define SIZE 10

void Push(int);
void Pop();
void Display();

int stack[SIZE], top = -1;

int main()
{
	int value, choice;
	while(1)
	{
		printf("\n---------------MENU---------------\n");
    	printf("\n 1.PUSH\n 2.POP\n 3.DISPLAY\n 4.EXIT");
	        printf("\n Nhap lua chon:");
	        scanf("%d",&choice);
	        switch(choice)
	        {
	            case 1:
	            {
	            	printf("Nhap gia tri can them vao STACK: ");
	            	scanf("%d", &value);
	                Push(value);
	                break;
	            }
	            case 2:
	            {
	                Pop();
	                break;
	            }
	            case 3:
	            {
	                Display();
	                break;
	            }
	            case 4:
	            {
	                printf("\n EXIT!!!");
	                break;
	            }
	            default:
	            {
	                printf ("\n Nhap lua chon 1, 2,3 hoac 4");
	            }
        	}
	}
		
}
void Push(int value)
{
    if(top == SIZE -1)
    	printf("\n STACK day! \n");
    else
    {
    	top ++;
    	stack[top] = value;
    	printf("%d vua duoc them vao STACK", value);
	}
}

void Pop()
{
	if( top == -1)
		printf("\nSTACK rong!\n");
	else
		printf("%d vua duoc xoa khoi Stack! \n", stack[top]);
		top--;
}

void Display()
{
	if(top == -1)
		printf("STACK rong!!");
	else
		{
			int i;
			printf("\nCac gia tri trong Stack: \n");
			for(int i = top ; i>= 0; i--)
				printf("%d ", stack[i]);
		}
}
		
