#include<iostream>
#include<algorithm>
#include<string>
#include <vector>
#define check cout<<"check"<<endl
#define rep(a,b,c) for(int a = b; a < c ;a++)
using namespace std;
void calcsort(int *,int,int);
int main(void){
    int n;
    cin>>n;
    int a[n];
    int max = 0;
    rep(i,0,n){
        cin>>a[i];
        if(max < a[i])max = a[i];
    }
    
    calcsort(a,n,max);
    return 0;


}

void calcsort(int *a,int n,int max){
    int c[max + 1];
    rep(i,0,max + 1)c[i] = 0;
    rep(i,0,n){
        c[a[i]]++;
    }
    rep(i,0,max){
        c[i + 1] += c[i];
    }
    int b[n];
    rep(i,0,n){
        int m = n - 1 - i;
        b[c[a[m]] - 1]= a[m];
        c[a[m]] -= 1;
    }
    rep(i,0,n){
        cout<<b[i];
        if(i != n - 1)cout<<" ";
    }
    cout<<endl;
    return ;
}