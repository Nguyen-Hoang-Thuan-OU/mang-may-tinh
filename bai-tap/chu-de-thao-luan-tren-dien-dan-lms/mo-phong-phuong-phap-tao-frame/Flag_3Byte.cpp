#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;
int a[100],F[100],E[100];
bool check(int x){
    bool kt1=true,kt2=true;
    for (int i=0;i<3;i++){
        if (a[x+i]!=E[i]) kt1=false;
        if (a[x+i]!=F[i]) kt2=false;
    }
    return (kt1||kt2);
}
int main(){
    srand(time(NULL));
    int n=(rand()%10)+10;
    cout<<"Flag :";
    for (int i=0;i<3;i++){
        F[i]=rand()%2;
        cout<<F[i];
    }
    cout<<endl;
    cout<<"ESC  :";
    for (int i=0;i<3;i++){
        E[i]=rand()%2;
        cout<<E[i];
    }
    cout<<endl;
    cout<<"Data  Send :";
    for (int i=0;i<n;i++){
        a[i]=rand()%2;
    }
    for (int i=0;i<n;i++)
        cout<<a[i];
    cout<<endl;
    cout<<"Frame Send :";
    int tmp=0;
    int i=0;
    for (int j=0;j<3;j++)
        cout<<F[j];
    cout<<" ";
    while (i<n){
        if (check(i) && (n-i)>=3){
            cout<<" ";
            for (int j=0;j<3;j++)
                cout<<E[j];
            cout<<" ";
            for (int j=0;j<3;j++)
                cout<<a[i+j];
            i+=3;
        }
        else{
            cout<<a[i];
            i++;
        }
    }
    cout<<" ";
    for (int j=0;j<3;j++)
        cout<<F[j];
    return 0;
}
