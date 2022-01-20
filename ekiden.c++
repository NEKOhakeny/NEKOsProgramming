#include<iostream>
#include<string>
#define rep(a,b,c) for(int a = b ; a < c ; a++)
int cnt;
int c[4];
using namespace std;

int shellsort(int *,int,int*);

int  insertionsort(int *,int,int );

int main(void){
    int n;
    cin>>n;
    int a[n];
    rep(i,0,n)cin>>a[i];
    int g[4] = {15,7,3,1};
    int cont = shellsort(a,n,g);
    cout<<cnt<<endl;
    rep(i,0,cnt)cout<<c[i]<<" ";
    cout<<endl;
    cout<<cont<<endl;
    rep(i,0,n)cout<<a[i]<<endl;
    
    return 0;
}
int shellsort(int *a,int n,int *g){
    int cont;
    rep(i,0,4){
        if(g[i] >= n)continue;
        cont = insertionsort(a,n,g[i]);
        c[cnt] = g[i];
        cnt++;

    }
    return cont;
}

int insertionsort(int *a,int n,int g){
    int b;
    static int cont = 0;
    rep(i,g,n){
        b = a[i];
        int j = i - g;
        while(a[j] > b && j >= 0){
            a[j + g] =  a[j];
            cont++;
            j = j - g;
        }
        a[j+g] = b;
        /*
        rep(k,0,n)cout<<a[k]<<" ";
        cout<<endl;
        */
    }
    return cont;
}

