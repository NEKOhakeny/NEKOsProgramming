#include<iostream>
#include<algorithm>
#include<cmath>
#include<climits>
#include<string>
#include <cstdlib>
#define rep(a,b,c) for(int a = b; a < c ;a++)
using namespace std;

int main(void) {
    int n;
    cin>>n;
    int ara[n];
    int num[n];
    string str[4 * n];
    rep(i,0,n)ara[i] = 0;
    rep(i,0,4 * n){
        cin>>str[i];
        cout<<"A"<<endl;
        if(str[i].find("\n") == string::npos)break;
        int a = atoi(str[i].c_str());
        cout<<a<<endl;
        ara[a - 1] += 1;
        num[a - 1] = a;
    }
    rep(i,0,n)if(ara[i] != 4)cout<<num[i]<<endl;
    return 0;
    
}