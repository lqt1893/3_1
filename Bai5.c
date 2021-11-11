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
bool nt(int a)//ktnt
{
	bool c=0;
	if (a==2||a==3)
	{
		c=1;
	}
	else
	{
		if (a>1)
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
void ca(int a[], int b[], int c)
{
	int i, d=0;
	for (i=1; i<=c; i++)
	{
		int j=a[i];
		if (nt(j)==1)
		{
			d++;
			b[d]=j;
		}
	}
	printf("Noi dung mang b: ");
	for (i=1; i<=d; i++)
		printf("%d ",b[i]);
}
void cb(int a[], int b[], int c[], int n)
{
	int i, d=0, e=0;
	for (i=1; i<=n; i++)
	{
		if (a[i]>0)
		{
			d++;
			b[d]=a[i];
		}
		else
		{
			e++;
			c[e]=a[i];
		}
	}
	printf("Mang b co noi dung la: ");
	for (i=1; i<=d; i++)
		printf("%d ", b[i]);
	printf("\nMang c co noi dung la: ");
	for (i=1; i<=e; i++)
		printf("%d ", c[i]);
}
void cc(int x[], int y)
{
	int i, j, d;
	for (i=1; i<=y; i++)
		for (j=i+1; j<=y; j++)
			if(x[i]<x[j])
			{
				d=x[i];
				x[i]=x[j];
				x[j]=d;
			}
}
void cd(int a[], int n, int b[], int c[])
{
	int i, d=0, e=0, f=0;
	for (i=1; i<=n; i++)
	{
		if (a[i]>0)
		{
			d++;
			b[d]=a[i];
		}
		if (a[i]<0)
		{
			e++;
			c[e]=a[i];
		}
		if (a[i]==0)
			f++;
	}
	cc(b, d);
	cc(c, e);
	for (i=1; i<=d; i++)
		a[i]=b[i];
	int j=e;
	for (i=d+1; i<=e+d; i++)
	{
		a[i]=c[j];
		j--;
	}
	for (i=n; i>=d+e; i--)
		a[i]=0;
	printf("Mang sau khi sap xep la:");
	for (i=1; i<=n; i++)
		printf(" %d", a[i]);
}
int main()
{
	int n, a[100000], b[100000], c[100000], i;
	printf("Nhap so luong phan tu trong mang: ");
	scanf("%d", &n);
	while (n<0)
	{
		printf("Vui long nhap lai so phan tu trong mang: ");
		scanf("%d", &n);
	}
	nh(a,n);
	ca(a, b, n);
	cb(a, b, c, n);
	cc(a, n);
	printf("Mang giam dan: ");
	for (i=1; i<=n; i++)
		printf("%d ", a[i]);
	cd(a, n, b, c);

}
