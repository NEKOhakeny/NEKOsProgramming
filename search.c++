#include<algorithm>
#include<iostream>
#include<string>
#include <vector>
#define check cout<<"check"<<endl
#define rep(a,b,c) for(int a = b; a < c ;a++)
using namespace std;
int judge(int,int *,int);
int sfunc(int,int,int *,int,int,int);
int main(void){
    int n;
    cin>>n;
    int a[n];
    rep(i,0,n)cin>>a[i];
    int q;
    cin>>q;
    int m[q];
    rep(i,0,q)cin>>m[i];
    rep(i,0,q){
        int ans = judge(m[i],a,n);
        if(ans == 1)cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }
    return 0;
}
int judge(int m,int *a,int n){
    int sum = 0;
    if(sfunc(sum,0,a,m,0,n) == 1 || sfunc(sum,1,a,m,0,n) == 1)return 1;
    else return 0;
}
int sfunc(int sum ,int num,int *a,int m,int i,int n){
    if(i >= n)return 0;
    if(num != 0)sum += a[i];
    if(sum == m)return 1;
    if(sum > m)return 0;
    i++;
    if(sfunc(sum,0,a,m,i,n) == 1 || sfunc(sum,1,a,m,i,n) == 1)return 1;
    else return 0;
}

