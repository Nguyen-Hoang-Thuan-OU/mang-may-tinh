#include <iostream>
#include <math.h>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	srand(time(NULL));
    int a[100];
    int n=(rand()%50)+10;
    cout<<"Data  Send :";
    for (int i=0;i<n;i++){
        a[i]=(rand()%9)+1;
        //cin>>a[i];
        cout<<a[i];
    }
    cout<<endl;
    cout<<"Frame Send :";
    int i=0;
    while (i<n){
        int k=(rand()%8)+2;
        if (i+k-1>n) k=n-i+1;
        cout<<k;
        for (int j=0;j<k-1;j++)
            cout<<a[i+j];
        i+=k-1;
        cout<<" ";
    }
    return 0;
}
