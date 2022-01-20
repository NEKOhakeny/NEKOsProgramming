#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
#define rep(a,b,c)   for(int a = b ; a < c ;a++)

int main(void){
    int n,q;
    int head,tail;
    head = tail = 0;
    cin>>n>>q;
    int a[n+1];
    char name[n+1][10];
    rep(i,0,n){
        cin>>name[i];
        cin>>a[i];
        tail++;
    }
    int m = n + 1;
    int count = 0;
    int word = n;
    while(word != 0){
        
        a[head] = a[head] - q;
        if(a[head] <= 0){
            cout<<name[head]<<" ";
            count = count + a[head] + q;
            cout<<count<<endl;
            word --;
            head = (head + 1) % m;
            continue;
         }
         count += q;
        a[tail] = a[head];
        strcpy(name[tail],name[head]);
         head = (head + 1) % m;
         tail = (tail + 1) % m;
         
    }
    
    return 0;
}
    