#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;

int main(){
    srand(time(NULL));
    int a[100];
    int n=(rand()%50)+10;
    cout<<"Data  Send :";
    for (int i=0;i<n;i++){
        a[i]=max((rand()%2),(rand()%2));
        //cin>>a[i];
        cout<<a[i];
    }
    cout<<endl;
    cout<<"Frame Send :";
    int tmp=0;
    for (int i=0;i<n;i++){
        cout<<a[i];
        if (a[i]==1){
            tmp+=1;
            if (tmp==5){
                tmp=0;
                cout<<" "<<0<<" ";
            }
        }
        else
            tmp=0;
    }
    return 0;
}

