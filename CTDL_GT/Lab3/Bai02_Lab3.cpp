/* Bai02: Rearrange the following numbers using Quick sort procedure. 42, 12, 18, 98, 67, 83, 8, 10, 71 */
#include <stdio.h>
#include <stdio.h>

void Swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void QuickSort(int arr[], int left, int right)
{
    int i, j, x;
    if (left >= right)
        return;
    x = arr[(left+right)/2]; 
    i = left; j = right;
    do{
        while(arr[i] < x)
            i++;
        while(arr[j] > x)
            j--;
        if(i <= j) 
		{
            Swap(arr[i], arr[j]);
                i++ ; j--; 
		}
    } while(i < j);
        if(left < j) 
			QuickSort(arr, left, j);
        if(i < right) 
			QuickSort(arr, i, right);
}

void xuatMang(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%d \t", arr[i]);
    }
}

int main()
{
    int arr[] = {42, 12, 18, 98, 67, 83, 8, 10, 71};
    int n = sizeof(arr)/sizeof(arr[0]);
    int left = 0, right = n-1;
    printf("Mang truoc khi sap xep: \n");
    xuatMang(arr,n);
    QuickSort(arr,left,right);
    printf("\nMang sau khi sap xep: \n");
    xuatMang(arr,n);

    return 0;
}
