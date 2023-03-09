#include <stdio.h>
#include <string.h>

struct HoTen{
	char hovaTen[30];
};
void nhapHoten(HoTen arr[], int &n)
{
	printf("Nhap so luong: ");
	scanf("%d", &n);
	for( int i=0; i< n; i++)
	{
		fflush(stdin);
		printf("Nhap ten thu %d: ", i+1);
		gets(arr[i].hovaTen);
	}
}
void Swap(HoTen &a, HoTen &b)
{
    HoTen t;
    t = a;
    a = b;
    b = t;
}
void BubbleSort(HoTen arr[], int n)
{
    for (int i=0; i<n-1; i++)
        for (int j=n-1; j>i; j--)
            if(strcmp (arr[i].hovaTen,arr[j].hovaTen) > 0){
            	 Swap(arr[j], arr[j-1]);
			}
}
void xuat(HoTen arr[], int n)
{
	printf("Cac ten da nhap: \n");
	for(int i =0; i< n; i++)
	{
		printf("\n%s", arr[i].hovaTen);
	}
}
int main()
{
	HoTen arr[100];
	int n;
	nhapHoten(arr,n);
	BubbleSort(arr,n);
	xuat(arr, n);
	
	return 0;
}
