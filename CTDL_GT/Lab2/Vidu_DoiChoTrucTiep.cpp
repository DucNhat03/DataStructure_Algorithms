#include <stdio.h>
void Swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
void InterchangeSort(int a[], int n)
{
    for (int i=0 ; i<n-1 ; i++)
        for (int j=i+1; j < n ; j++)
            if(a[i]>a[j]) //nếu có nghịch thế thì đổi chỗ
                Swap(a[i], a[j]);
}
int main()
{
    int a[20];
    int n;
    printf("Nhap so luong: ");
    scanf("%d", &n);
    for(int i =0; i< n; i++)
    {
        printf("Nhap gia tri a[%d]: ", i);
        scanf("%d", &a[i]);
    }
    printf("Mang truoc khi sap xep: ");
    for(int i =0; i< n; i++)
    {
        printf("%d ", a[i]);
    }
    InterchangeSort(a,n);
    printf("\nMang sau khi sap xep: ");
    for(int i =0; i< n; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}


