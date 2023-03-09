#include <stdio.h>
void Swap(int &a, int &b)
{
    int t;
    t = a;
    a = b;
    b = t;
}
void InsertionSort(int a[], int n)
{
    int pos;
    for (int i = 0; i < n; i++)
    {
        pos = i;
        while (pos > 0 && a[pos] < a[pos-1])
        {
            Swap(a[pos], a[pos-1]);
        pos--;
        }
    }
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
    InsertionSort(a,n);
    printf("Mang sau khi sap xep: ");
    for(int i =0; i< n; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}
