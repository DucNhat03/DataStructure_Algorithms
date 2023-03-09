/* Compose a program to implement Queue operation using arrays*/
#include<stdio.h>
#include<stdlib.h>
#include <queue>
#define maxsize 5
void themPhanTu();
void xoaPhanTu();
void xuatPhanTu();
int front = -1, rear = -1;
int queue[maxsize];
int main ()
{
    int choice;
    while(choice != 4)
    {
        printf("\n=========MENU==========\n");
        printf("\n1.Them phan tu\n2.Xoa phan tu\n3.Xuat phan tu\n4.Thoat chuong trinh\n");
        printf("\nNhap lua chon: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            	themPhanTu();
            	break;
            case 2:
           		xoaPhanTu();
            	break;
            case 3:
            	xuatPhanTu();
            	break;
            case 4:
            	exit(0);
            	break;
            default:
            printf("\nChon 1,2,3 hoac 4 thoi!\n");
        }
    }
}
void themPhanTu()
{
    int item;
    printf("\nNhap gia tri can them: ");
    scanf("\n%d",&item);
    if(rear == maxsize-1)
    {
        printf("\nOverFlow\n");
        return;
    }
    if(front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
    }
    else
    {
        rear = rear+1;
    }
    queue[rear] = item;
    printf("\nThem vao thanh cong!");

}
void xoaPhanTu()
{
    int item;
    if (front == -1 || front > rear)
    {
        printf("\nKhong co phan tu nao de xoa\n");
        return;

    }
    else
    {
        item = queue[front];
        if(front == rear)
        {
            front = -1;
            rear = -1 ;
        }
        else
        {
            front = front + 1;
        }
        printf("\nXoa thanh cong!!");
    }


}

void xuatPhanTu()
{
    int i;
    if(rear == -1)
    {
        printf("\nRong!\n");
    }
    else
    {   printf("\nXuat cac gia tri vua nhap: ");
        for(i=front;i<=rear;i++)
        {
            printf("\n%d\n",queue[i]);
        }
    }
}
