#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
using namespace std;
#define rep(a,b,c)   for(int a = b ; a < c ;a++)
int partdiv(int *,int);
int main(void){
    int n;
    cin>>n;
    int a[n];
    rep(i,0,n)cin>>a[i];
    int div = partdiv(a,n);
    rep(i,0,n){
        if(i != div){
            cout<<a[i];
            if(i != n - 1)cout<<" ";
            continue;
        }
        cout<<"["<<a[i]<<"]";
        if(i != n - 1)cout<<" ";
    }
    cout<<endl;
    return 0;
}

int partdiv(int *a,int n){
    int stnd = a[n - 1];
    int div = 0;
    rep(i,0,n - 1){
        if(a[i] > stnd)continue;
        int b = a[div];
        a[div] = a[i];
        a[i] = b;
        div++;
    }
    int b = a[div];
    a[div] = a[n - 1];
    a[n - 1] = b;
    return div;

}