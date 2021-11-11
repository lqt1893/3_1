#include <stdio.h>
#include <stdbool.h>
#include <math.h>
void nh(int x[], int y)
{
	int i;
	for (i=1; i<=y; i++)
	{
		printf("Nhap phan tu thu %d: ", i);
		scanf("%d", &x[i]);
	}
}
int ca(int x[], int y, int z)
{
	int i=y;
	bool c=0;
	do
	{
		if (x[i]==z)
		{
			c=1;
			return i;
		}
		else i--;
	}
	while (i>=0&&x[i+1]!=z);
	if 	(c==0)
		return 0;		
}
int cb(int x[], int y)
{
	int i=1;
	bool c=0;
	while (i<=y&&c==0)
		if (x[i]=2||x[i]==3)
			c=1;
		else
		{
			if (x[i]<=0||x[i]==1)
				i++;
			else
			{
				int i;
				for(i=2; i<=sqrt(x[i]); i++)
				{
					c=1;
					if(x[i]%i==0)
					{
						c=0;
						i++;
					}
				}
			}
		}
	if(c==1)
		return i;
	else
		return 0;
}
void cc(int x[], int y)
{
	int i=1, s=x[1];
	for (i=2; i<=y; i++)
	{
		if (s>x[i])
			s=x[i];
	}
	printf("So nho nhat trong mang la: %d\n", s);
}
void cd(int x[], int y)
{
	int i=1, s=x[1];
	for (i=2; i<=y; i++)
	{
		if (s>x[i]||s<=0)
			s=x[i];
	}
	if (s>0)
		printf("So duong nho nhat trong mang la: %d", s);
	if (s<=0)
		printf("Khong co so duong");
}
int main()
{
	int n, a[100000], x, vta, vtb;
	printf("Nhap so luong phan tu trong mang: ");
	scanf("%d", &n);
	while (n<=0)
	{
		printf("Vui long nhap lai so phan tu trong mang: ");
		scanf("%d", &n);
	}
	nh(a,n);
	printf("Nhap phan tu can tim kiem: ");
	scanf("%d", &x);
	vta=ca(a, n, x);//cau a
	if (vta!=0)
		printf("Vi tri cuoi cung cua phan tu %d trong mang la: %d\n", x, vta);
	else
		printf("Khong co phan tu %d trong mang\n", x);
	vtb=cb(a, n);
	if(vtb==0)
		printf("Khong co so nguyen to\n");
	else
		printf("Vi tri so nguyen to dau tien trong mang la: %d\n", vtb);
	cc(a, n);
	cd(a, n);
}
