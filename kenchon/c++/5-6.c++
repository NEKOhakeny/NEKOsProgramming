#include <bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<climits>
#include<vector>
#define check cout<<"check"<<" "
#define rep(a,b,c)   for(int a = b ; a < c ;a++)
#define roop(i,n) for (int i = 0; i < (n); ++i)
#define INF INT_MAX - 2
using namespace std;
using REF = vector< vector<int> > ;
using aray = vector< int >;
using namespace std;

template <class T> void chmin(T &a,T b)
{
    if(a > b)a = b;
}

int main()
{
    int n,w;
    cin>>n>>w;
    aray a(n),m(n);
    roop(i,n)cin>>a[i]>>m[i];
    REF dp(n,aray(w + 1,0));
    for(int i = 1; i < m[0] ; i++)
    {
        if(i * a[0] > w)break;
        dp[0][a[0] * i] = dp[0][a[0] * (i - 1)] + 1;
    }
    rep(i,1,n)
    {
        roop(j,w + 1)
        {
            dp[i][j] = dp[i - 1][j];
            
        }
    }

    return 0;
}