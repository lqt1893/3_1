#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdbool.h>
void nh(int x[], int y)
{
	int i;
	for (i=1; i<=y; i++)
	{
		printf("Nhap phan tu thu %d: ", i);
		scanf("%d", &x[i]);
	}
}
bool nt(int a)//ktnt
{
	bool c=0;
	if (a==2||a==3)
	{
		c=1;
	}
	else
	{
		if (a>3)
		{
			int i;
			for(i=2; i<=sqrt(a); i++)
			{
				c=1;	
				if(a%i==0)
				{
					c=0;
					break;
				}
			}
		}
	}
	return c;
}
void ca(int a[], int n)
{
	int i;
	for (i=1; i<=n; i++)
	{
		int j=a[i];
		if (nt(j)==1)
			a[i]=0;
	}
	printf("a) Mang a sau khi sua la:");
	for (i=1; i<=n; i++)
	{
		printf(" %d", a[i]);
	}
}
void cb(int a[], int n)
{
	int i=1;
	while(i<=n)
	{
		int j=a[i];
		if (nt(j)==1)
		{
			n++;
			int k;
			for(k=n; k>=i+2; k--)
				a[k]=a[k-1];
			a[i+1]=0;
			i=i+2;
		}
		else
			i++;
	}
	for (i=1; i<=n; i++)
		printf("%d ", a[i]);
}
void cc(int a[], int n)
{
	int i=1;
	while(i<=n)
	{
		int j=a[i];
		if (nt(j)==1)
		{
			n--;
			int k;
			for(k=i; k<=n; k++)
				a[k]=a[k+1];
			a[n+1]=0;
		}
		else
			i++;
	}
	for (i=1; i<=n; i++)
		printf("%d ", a[i]);
}
int main()
{
	int n, a[100000], i;
	printf("Nhap so luong phan tu trong mang: ");
	scanf("%d", &n);
	while (n<=0)
	{
		printf("Vui long nhap lai so phan tu trong mang: ");
		scanf("%d", &n);
	}
	nh(a,n);
	ca(a, n);
	//cb(a, n);
	//cc(a, n);
}
