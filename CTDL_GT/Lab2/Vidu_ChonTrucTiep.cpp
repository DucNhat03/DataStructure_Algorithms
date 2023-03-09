#include <stdio.h>
void Swap(int &a, int &b)
{
    int t;
    t = a;
    a = b;
    b = t;
}
void SelectionSort(int a[], int n )
{
    int min; // chỉ số phần tử nhỏ nhất trong dãy hiện hành
    for (int i=0; i<n-1; i++)
    {
        min = i;
        for(int j = i+1; j<n; j++)
        if (a[j] < a[min])
        min = j; // ghi nhận vị trí phần tử nhỏ nhất
        if (min != i)
        Swap(a[min], a[i]);
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
    SelectionSort(a,n);
    printf("Mang sau khi sap xep: ");
    for(int i =0; i< n; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}
