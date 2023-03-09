//Sap xep giam dan bang Bubble Sort.
#include <stdio.h>
void nhapMang(int a[], int n)
{
    for(int i =0; i< n; i++)
    {
        printf("Nhap gia tri a[%d]: ", i);
        scanf("%d", &a[i]);
    }
}
void xuatMang(int a[], int n)
{
     for(int i =0; i< n; i++)
    {
        printf("%d ", a[i]);
    }
}
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
            if(a[j] > a[j-1])
                Swap(a[j], a[j-1]);
}
int main()
{
    int a[20];
    int n;
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);
    nhapMang(a,n);
    printf("\nMang truoc khi sap xep: \n");
    xuatMang(a,n);

    printf("\n\nMang sau khi sap xep: \n");
    BubbleSort(a,n);
    xuatMang(a,n);
    return 0;
}
