#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct DaiLy{
	char shopName[30];
	char phoneNumber[15];
	double income;
};
struct NodeDaiLy{
	DaiLy data;
	struct NodeDaiLy *nextDL;
};

struct NodeTP{
	char cityName[30];
	struct NodeTP *nextTP;
	struct NodeDaiLy *downDL;
};
NodeTP* cityList = NULL;

NodeDaiLy *nhapThongTinDaiLy();
NodeTP *nhapThongTinThanhPho();
NodeTP *SearchCityName(char*newName);
NodeDaiLy *SearchNameShop(char*newName, NodeTP *city);
void NhapDanhSachThanhPho();
void Swap(char *p1,char *p2);
void SortCityList();
void SortShopList();
void xuatDSThanhPho();
void menu(NodeTP *city);
void quanLiDaiLy();
void baoCaoTheoTieuChi();

int main()
{
	printf("Nhap danh sach thanh pho\n");
	NhapDanhSachThanhPho();
	SortCityList();
	SortShopList();
	printf("\n");
	printf("\nXuat danh sach thanh pho\n");
	xuatDSThanhPho();
	printf("\n");
	printf("\nQuan li dai ly tai thanh pho\n");
	quanLiDaiLy();
	printf("\n");
	printf("\nDanh sach dai ly sau khi cap nhat\n");
	xuatDSThanhPho();
	printf("\n");
	printf("Bao cao thong ke\n");
	baoCaoTheoTieuChi();
	return 0;
}

NodeDaiLy *nhapThongTinDaiLy()
{
	NodeDaiLy *newDaiLy = (NodeDaiLy*)malloc(sizeof(NodeDaiLy));
	printf("\tNhap ten dai ly: ");
	fflush(stdin);
	gets(newDaiLy->data.shopName);
	printf("\tNhap so dien thoai: ");
	fflush(stdin);
	gets(newDaiLy->data.phoneNumber);
	printf("\tNhap doanh thu: ");
	scanf("%lf",&newDaiLy->data.income);
	newDaiLy->nextDL = NULL;
	return newDaiLy;
}

NodeTP *nhapThongTinThanhPho()
{
	NodeTP *newCity = (NodeTP*)malloc(sizeof(NodeTP));
	printf("\tNhap ten thanh pho: ");
	fflush(stdin);
	gets(newCity->cityName);
	newCity->nextTP = NULL;
	newCity->downDL = NULL;
	return newCity;
}

NodeTP *SearchCityName(char* newName)
{
	for (NodeTP*tmp= cityList; tmp!=NULL; tmp=tmp->nextTP)
		if (strcmp(tmp->cityName, newName)==0)
            return tmp;
	return NULL;
}

void NhapDanhSachThanhPho()
{
	int m, n;
	printf("Nhap so luong thanh pho: ");
	scanf("%d",&n);
	for (int i = 0; i<n; i++){
		printf("\nNhap thong tin thanh pho %d\n",i+1);
		NodeTP *city = nhapThongTinThanhPho();
		if (SearchCityName(city->cityName) == NULL){
			if (cityList == NULL ){
				cityList = city;
			}
			else{
				NodeTP *tmp = cityList;
				while (tmp->nextTP!=NULL) tmp= tmp->nextTP;
				tmp->nextTP = city;
			}

			printf("\tNhap so luong dai ly: ");
			scanf("%d",&m);
			NodeDaiLy* shopList = NULL;
			for (int j = 0; j < m; j++)
            {
				printf("\tNhap Thong tin dai ly %d\n",j+1);
				NodeDaiLy *shop = nhapThongTinDaiLy();
				if (shopList == NULL){
					shopList = shop;
				}
				else{
					NodeDaiLy *tmp = shopList;
					while (tmp->nextDL!=NULL)
                        tmp = tmp->nextDL;
                        tmp->nextDL = shop;
				}
			}
			city->downDL = shopList;
		}
		else
            printf("\nThanh pho da ton tai trong danh sach!\n");
	}
}

void Swap(char *p1,char *p2){
    char p3[30];
    strcpy(p3,p1);
    strcpy(p1,p2);
    strcpy(p2,p3);
}

void SortCityList(){
	for (NodeTP*tmp1 = cityList; tmp1!=NULL; tmp1=tmp1->nextTP)
	{
		for (NodeTP*tmp2 = cityList; tmp2!=NULL; tmp2=tmp2->nextTP)
        {
			if (strcmp(tmp1->cityName, tmp2->cityName) > 0)
			{
				Swap(tmp1->cityName, tmp2->cityName);
				NodeDaiLy *tmp = tmp1->downDL;
				tmp1->downDL = tmp2->downDL;
				tmp2->downDL = tmp;
			}
		}
	}
}

void SortShopList(){
	for (NodeTP*tmp = cityList; tmp!=NULL; tmp=tmp->nextTP)
    {
		for (NodeDaiLy*i = tmp->downDL; i!=NULL; i=i->nextDL)
        {
			NodeDaiLy *minNode = i;
			for (NodeDaiLy*j = i->nextDL; j!=NULL; j=j->nextDL)
			{
				if (minNode->data.income > j->data.income)
					minNode = j;
			}
			DaiLy tmp = minNode->data;
			minNode->data = i->data;
			i->data = tmp;
		}
	}
}

void xuatDSThanhPho()
{
	for (NodeTP*tmp1 = cityList; tmp1!=NULL; tmp1=tmp1->nextTP)
    {
		printf("\nTEN THANH PHO: %s\n",tmp1->cityName);
		for (NodeDaiLy*tmp2 = tmp1->downDL; tmp2!=NULL; tmp2=tmp2->nextDL)
		{
			printf("THONG TIN DAI LY\n");
			printf("\tTen dai ly: %s\n",tmp2->data.shopName);
			printf("\tSo dien thoai: %s\n",tmp2->data.phoneNumber);
			printf("\tDoanh thu: %.2lf\n",tmp2->data.income);
		}
	}
}

NodeDaiLy *SearchNameShop(char*newName, NodeTP *city){
	for (NodeDaiLy*tmp = city->downDL; tmp!=NULL; tmp=tmp->nextDL){
		if (strcmp(tmp->data.shopName, newName)==0)
            return tmp;
	}
	return NULL;
}

void menu(NodeTP *city)
{
	int choice = -1;
	while (choice != 0)
    {
		printf("\n\t1.THEM DAI LY\n");
		printf("\t2.CAP NHAT THONG TIN DAI LY\n");
		printf("\t3.XOA MOT DAI LY KHOI DANH SACH\n");
		printf("\t4.TIM KIEM DAI LY\n");
		printf("\t0.EXIT!!");
		printf("\nNhap lua chon cua ban: ");
		scanf("%d",&choice);

		switch (choice)
		{
			case 1:
            {
				NodeDaiLy *shop = nhapThongTinDaiLy();
				if (shop->data.income <= city->downDL->data.income)
                {
					shop->nextDL = city->downDL;
					city->downDL = shop;
				}
				else
                {
					NodeDaiLy *tmp = city->downDL;
					while (tmp->nextDL != NULL && (tmp->data.income < shop->data.income ))
                    {
						if (tmp->nextDL->data.income > shop->data.income )
                        {
							shop->nextDL = tmp->nextDL;
							tmp->nextDL = shop;
							break;
						}
						tmp = tmp->nextDL;
					}

					if (tmp->nextDL == NULL)
                    {
							NodeDaiLy *tmp2 = city->downDL;
							while (tmp2->nextDL != NULL) tmp2 = tmp2->nextDL;
							tmp2->nextDL = shop;
					}
				}
				break;
			}

			case 2:
            {
				char tenDL[30];
				printf("\tNhap ten dai ly muon thay doi thong tin: ");
				fflush(stdin);
				gets(tenDL);
				NodeDaiLy *shop = SearchNameShop(tenDL, city);
				if (shop == NULL)
					printf("\tKhong tim thay dai ly muon quan ly!\n");
				else
                {
					NodeDaiLy *shop = SearchNameShop(tenDL, city);
					printf("\t\t\tNhap ten dai ly: ");
					fflush(stdin);
					gets(shop->data.shopName);
					printf("\t\t\tNhap so dien thoai: ");
					fflush(stdin);
					gets(shop->data.phoneNumber);
					printf("\t\t\tNhap doanh thu: ");
					scanf("%lf",&shop->data.income);
				}
				break;
			}

			case 3:
            {
				char tenDL[30];
				printf("\tNhap ten dai ly muon xoa khoi danh sach: ");
				fflush(stdin);
				gets(tenDL);
				NodeDaiLy *shop = SearchNameShop(tenDL, city);
				if (shop == NULL)
					printf("\tKhong tim thay dai ly muon xoa!\n");
				else{
					if (shop == city->downDL){
						if (city->downDL == NULL) return;
						NodeDaiLy *tmp = city->downDL;
						city->downDL = tmp->nextDL;
						free(tmp);
					}
					else
                    {
						NodeDaiLy* tmp = cityList->downDL;
						while (tmp->nextDL != shop)
                        {
            				tmp = tmp->nextDL;
        				}
						NodeDaiLy *t = tmp->nextDL;
						tmp->nextDL = t->nextDL;
					}
				}
				break;
			}

			case 4:
            {
				char sName[30];
				printf("\tNhap ten dai ly can tim kiem: ");
				fflush(stdin);
				gets(sName);
				if (SearchNameShop(sName, city) == NULL)
					printf("\tKhong tim thay dai ly trong danh sach!\n");
				else
					printf("\tTim thay dai ly trong danh sach!\n");
				break;
			}
			case 0:
            {
				printf("\n\tEXIT !!");
				exit;
				break;
			}

			defaut:
            {
				printf("\nVui long nhap lai lua chon\n");
				break;
			}

		}
	}
}

void quanLiDaiLy()
{
	char tenDL[30];
	printf("Nhap ten thanh pho muon quan ly: ");
	fflush(stdin);
	gets(tenDL);
	NodeTP *city = SearchCityName(tenDL);
	if (city == NULL)
		printf("\nDai ly can tim khong ton tai\n");
	else
		menu(city);
}

void baoCaoTheoTieuChi()
{
	printf("\nTinh tong doanh thu cua thanh pho trong danh sach");
	char maxCityName[30] = "", minCityName[30] = "";
	double maxIncomeCity = 0, minIncomeCity;
	for (NodeTP*tmp1 = cityList; tmp1!=NULL; tmp1=tmp1->nextTP)
    {
		double sum = 0;
		for (NodeDaiLy*tmp2 = tmp1->downDL; tmp2!=NULL; tmp2=tmp2->nextDL)
		{
			sum +=tmp2->data.income;
		}

		if (maxIncomeCity<sum)
        {
			maxIncomeCity = sum;
			strcpy(maxCityName, tmp1->cityName);
		}
		else{
			minIncomeCity = sum;
			strcpy(minCityName, tmp1->cityName);
		}
		printf("\nThanh pho: %-20s\n", tmp1->cityName);
		printf("Tong doanh thu: %20.lf", sum);
	}
	printf("\nDoanh thu cao nhat trong thanh pho la: %.2lf", maxIncomeCity);

}



