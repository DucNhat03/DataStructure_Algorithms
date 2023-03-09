#include <stdio.h>
void Swap(int &a, int &b)
{
    int t;
    t = a;
    a = b;
    b = t;
}
void BubbleSort(int a[], int n)
{
    for (int i=0; i<n-1; i++)
        for (int j=n-1; j>i; j--)
            if(a[j] < a[j-1])
                Swap(a[j], a[j-1]);
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
    BubbleSort(a,n);
    printf("Mang sau khi sap xep: ");
    for(int i =0; i< n; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}

