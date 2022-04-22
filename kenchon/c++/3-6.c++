#include <bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<climits>
#include<vector>
#define check cout<<"check"<<endl
#define rep(a,b,c)   for(int a = b ; a < c ;a++)
#define roop(i,n) for (int i = 0; i < (n); ++i)
#define INF 1000100100
using namespace std;
using REF = vector< vector<int> > ;
using aray = vector< int >;
using namespace std;

int main(){
    int n;
    string s;
    cin>>s;
    n = s.length();
    long int sum = 0;
    roop(k,1 << (n - 1))
    {
        
        long int tmp = 0;
        rep(i,0,n - 1)
        {
            tmp *= 10;
            tmp += s[i] - '0';
            if(k & 1 << i)
            {
                sum += tmp;
                tmp = 0;     
            }
        }
        tmp *= 10;
        tmp += s.back() - '0';
        sum += tmp; 
    }
    cout<<sum<<endl;
    return 0;
}