#include<iostream>
#define rep(a,b,c) for(int a = b ; a < c ; a++)
using namespace std;
int shellsort(int *,int *,int);
void insort(int ,int *,int *,int);
int main(void){
    int n;
    cin>>n;
    int a[n];
    rep(i,0,n)cin>>a[i];
    int g[n];
    g[0] = 1;
    int cnt = shellsort(a,g,n);
    cout<<cnt<<endl;
    rep(i,0,n)cout<<a[i]<<endl;
    return 0;
}
int shellsort(int *a,int *g,int n){
    int b[4];
    int count = 1;
    int cnt = 0;
    rep(i,1,n){
        int a = g[i - 1] * 2 + 1; 
        if(a > n)break;
        count++;
        g[i] = a;
    }
    cout<<count<<endl;
    rep(i,0,count)insort(g[count - i - 1 ],&cnt,a,n);
    cout<<endl;
    return cnt;

}
void insort(int g,int *cnt,int *a,int n){
    cout<<g<<" ";
    for(int i = g; i < n  ; i++){
        int v = a[i];
        int j;
        for(j = i - g; j >= 0 ; j -= g){
            if(a[j] <= v)break;
            a[j + g] = a[j];
            *cnt += 1;
        }
        a[j+g] = v; 
    }
    return ;
}