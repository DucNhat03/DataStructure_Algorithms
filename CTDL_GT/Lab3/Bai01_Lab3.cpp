/* Bai01: Apply the selection sort on the following elements 21,11,5,78,49, 54,72,88 */
#include <stdio.h>
void Swap( int &a, int &b)
{
    int t;
    t = a;
    a = b;
    b = t;
}
void SelectionSort(int arr[], int n)
{
    int min;
    for(int i = 0; i < n-1; i++)
    {
        min = i;
        for(int j = i+1; j < n; j++)
		{
		
        	if(arr[j] < arr[min])
                min = j;
		}
        if( min != i)
            Swap(arr[min],arr[i]);
    }
}
void xuatMang(int arr[], int n)
{
    for(int i =0; i< n; i++)
    {
        printf("%d \t", arr[i]);
    }
}
int main()
{
    int arr[] = {21,11,5,78,49, 54,72,88};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Mang truoc khi sap xep: \n");
    xuatMang(arr,n);
    printf("\nMang sau khi sap xep: \n");
    SelectionSort(arr,n);
    xuatMang(arr,n);
    return 0;
}
