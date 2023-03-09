#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

struct SinhVien{
	int MaSinhVien;
	char HoTen[50];
	float Diem;
};

void Nhap(SinhVien a[], int &sl);
void Xuat(SinhVien a[], int sl);
void Swap(SinhVien &a, SinhVien &b);
void InsertionSort(SinhVien a[], int N);

void Nhap(SinhVien a[], int &sl){
	printf("Nhap so luong sinh vien: "); 
	scanf("%d",&sl);
	for(int i=0;i<sl; i++){
		printf("\n");
		printf("Nhap ma sinh vien: ");
		scanf("%d",&a[i].MaSinhVien);
		printf("Ho va ten: ");
		fflush(stdin);gets(a[i].HoTen);
		printf("Diem: ");
		scanf("%f",&a[i].Diem);
		
	}
}

void Xuat(SinhVien a[], int sl){
	
	printf("\n%10s %20s %20s","MaSV","HoTen","Diem");
	for(int i=0;i<sl;i++){
		printf("\n%10d %20s %20.2f",a[i].MaSinhVien,a[i].HoTen,a[i].Diem);
	}
}
void Swap(SinhVien &a, SinhVien &b){
   	SinhVien temp;
	temp = a;
   	a = b;
	b = temp;
}

void InsertionSort(SinhVien a[], int N)
{
   for (int i = 0; i < N; i++)
   {
       for (int j = N-1; j > i; j--)
	   {
           if(a[i].Diem < a[j].Diem)
		   {
           		Swap(a[j], a[j-1]);
		   }               
       }
   }
}
int main()
{
	SinhVien sv[100];
	int n;
	Nhap(sv,n);
	Xuat(sv,n);
	InsertionSort(sv,n);
	Xuat(sv,n);
	
	return 0;
}
