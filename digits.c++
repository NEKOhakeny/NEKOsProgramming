#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<string>
#include<cstdio>
#define N 5000
#define rep(a,b,c) for(int a = b ; a < c ; a++)
using namespace std;
int  stack[100];

int main(void){
    int n,m;
    cin>>n>>m;
    string hutu[n];
    string kyukou[m];
    rep(i,0,n)cin>>hutu[i];
    rep(i,0,m)cin>>kyukou[i];
    rep(i,0,n){
        int judge = 0;
        rep(j,0,m){
            //cout<<kyukou[j]<<" "<<hutu[i]<<endl;
            if(hutu[i] == kyukou[j]){
                judge = 1;
                //cout<<kyukou[j]<<" "<<hutu[i]<<endl;
                cout<<"Yes"<<endl;
                break;
            }
        }
        if(judge == 0)cout<<"No"<<endl;
    }
    return 0;

    
}