#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;
void nhap(int a[],int n) {
	srand((int)time(0));
	for (int i = 0; i < n; i++)
	{
		a[i] = rand()%2;
	}
	//for (int i = 0; i < n; i++)
	//	cin >> a[i];
}
void xuat(int a[], int n) {
	for (int i = 0; i < n; i++)
	{
		cout<<a[i];
	}
}
void dem(int a[], int n) {
	int  k, tam = 0, vt = 0;
	cout << "\nData send : ";
	nhap(a, n);
	xuat(a, n);
		for (int i = 0; i < n; i++) {
			if (a[i] == 1)
			{
				tam++;
				if (tam == 5)
				{
					vt = i + 1;
					tam = 0;
					for (int j = n; j >= vt; j--) {
						k = j + 1;
						a[k] = a[j];
					}
					a[vt] = 0;
					n = n + 1;
				}
			}
			else
				tam = 0;
		}
	cout << "\n FRAME SEND \n";
	cout << " 01111110 ";
	xuat(a, n);
	cout << " 01111110 ";
}
int main()
{
	int a[200];
	int n;
	cout<<"\n Nhap bit: ";
	cin >> n;
	dem(a, n);
	system("pause");
	return 0;
}



