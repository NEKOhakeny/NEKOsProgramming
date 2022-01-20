#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
using namespace std;
#define rep(a,b,c)   for(int a = b ; a < c ;a++)
void partdiv(int,int,char *,int *);
int main(void){
    int n;
    cin>>n;
    char a[n];
    int b[n];
    rep(i,0,n){
        cin>>a[i];
        cin>>b[i];
        partdiv(a,b,0,n)
    }
}

int partdiv(char *b,int  *a,int p,int r){
    int stnd = a[r - 1];
    int div = p;
    rep(i,p,r - 1){
        if(a[i] > stnd)continue;
        int c = a[div];
        a[div] = a[i];
        a[i] = c;
        char d = b[div];
        b[div] = b[i];
        b[i] = d;
        div++;
    }
    int c = a[div];
    a[div] = a[r - 1];
    a[r - 1] = c;
    char d = b[div];
    b[div] = b[r - 1];
    b[r - 1] = d;
    partdiv()

}