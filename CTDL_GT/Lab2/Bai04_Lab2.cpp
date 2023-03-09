//Sap xep N nhan vien theo luong bang Insertion Sort.
#include <stdio.h>
#include <string.h>
struct Employee
{
    int ma;
    char ten[20];
    float luong;
};

int main()
{
    Employee NV[10];
    int n;
    printf("Nhap so luong nhan vien: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        printf("Nhap ma nhan vien thu %d: ", i+ 1);
        scanf("%d", &NV[i].ma);
		fflush(stdin);
        printf("Nhap ten cua nhan vien thu %d: ", i+1);
        gets(NV[i].ten);
        printf("Nhap luong cua nhan vien thu %d: ", i +1);
        scanf("%f", &NV[i].luong); 
    }
    printf("\nDanh sach nhan vien truoc khi sap xep!\n");
    printf("%-15s %-15s %-15s\n", "Ma NV", "Ten NV", "Luong NV");
    for(int i =0; i< n; i++)
    {
     	printf("%-15d %-15s %-15.2f\n", NV[i].ma, NV[i].ten, NV[i].luong);
	}
	int pos;
    for (int i = 0; i < n; i++)
    {
        pos = i;
        while (pos > 0 && NV[pos].luong < NV[pos-1].luong)
        {
            float temp;
			temp = NV[pos].luong;
			NV[pos].luong = NV[pos-1].luong;
			NV[pos-1].luong = temp;
        	pos--;
        }
    }
    printf("\nDanh sach nhan vien sau khi sap xep!\n");
    printf("%-15s %-15s %-15s\n", "Ma NV", "Ten NV", "Luong NV");
    for(int i =0; i< n; i++)
    {
     	printf("%-15d %-15s %-15.2f\n", NV[i].ma, NV[i].ten, NV[i].luong);
	}
	
	return 0;
}
