#include <iostream>
using namespace std;
void xuat(int a[], int n);
void nhap(int a[], int n);
bool kt(int Data[], int Object[], int i, int nObject);
void xuLyDuLieu(int Frame[], int Flag[], int ESC[], int& nFrame, int nFlag, int nESC);
void chenMang(int a[], int b[], int& nA, int nB, int Vitri);
void copyArray(int a[], int n, int b[]);
int main() {
	int Flag[50];
	int ESC[50];
	const int MAX = 100;
	int Data[MAX];
	int Frame[MAX + 200];
	
	cout << "nhap Flag:";
	nhap(Flag, 8);     //vi Flag la Byte nen co do dai bang 8
	xuat(Flag, 8);
	cout << "\nnhap ESC:";
	nhap(ESC, 8);
	xuat(ESC, 8);
	cout << "\n";
	cout << "\nnhap do dai cua du lieu can gui: ";
	int n;
	cin >> n;
	cout << "\nNhap du lieu can gui: ";
	nhap(Data, n);
	
	cout << "\n";
	copyArray(Data, n, Frame);
	xuat(Frame, n);
	cout << "\n";	
	xuLyDuLieu(Frame, Flag, ESC, n, 8, 8);
	cout << "Du lieu tren duong truyen la: \n";
	xuat(Frame, n);
	cout << "\n Do dai : " << n;
	return 0;
}
void nhap(int a[], int n) {
	cout << "\n Nhap " << n << " bit 0 va 1(nhap moi bit tren mot dong): \n";
	for (int i = 0; i < n; i++)
		do {
			cin >> a[i];
			if (a[i] != 0 && a[i] != 1)
				cout << "Nhap sai! Nhap lai:\n";
		} while(a[i] != 0 && a[i] != 1);
		
}
void xuat(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << "\t";
}
bool kt(int Data[], int Object[], int i, int nObject)
{

	for (int j = 0; j < nObject; j++)
		if (Data[i + j] != Object[j])
			return false;
	return true;
}
void xuLyDuLieu(int Frame[], int Flag[], int ESC[], int& nFrame, int nFlag, int nESC) {
	int n;
	if (nFlag > nESC)
		n = nFrame - nESC + 1;
	else
		n = nFrame - nFlag + 1;
	//for (int i = 0; i < n; i++)
	int i = 0;
	while (i < n)
		if (kt(Frame, Flag, i, nFlag) || kt(Frame, ESC, i, nESC))
		{
			chenMang(Frame, ESC, nFrame, nESC, i);
			
			if(kt(Frame, Flag, i, nFlag))
				i = i + nESC + nFlag;
			else
				i = i + 2 * nESC;
			n += nESC;
		}
		else
			i++;
	chenMang(Frame, Flag, nFrame, nFlag, 0);
	chenMang(Frame, Flag, nFrame, nFlag, nFrame);

}

void chenMang(int a[], int b[], int& nA, int nB, int Vitri)
{
	for (int i = 0; i < nB; i++)
	{
		for (int j = nA; j > Vitri + i; j--)
			a[j] = a[j - 1];
		a[Vitri + i] = b[i];
		nA++;
	}
}
void copyArray(int a[], int n, int b[])
{
	for (int i = 0; i < n; i++)
		b[i] = a[i];
}