#include <bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<climits>
#include<vector>
#define check cout<<"check"<<endl
#define rep(a,b,c)   for(int a = b ; a < c ;a++)
#define roop(i,n) for (int (i) = 0; (i) < (n); ++(i))
#define N 100000
using namespace std;
using REF = vector< vector<bool> > ;
using aray = vector< bool >;
using namespace std;

int main()
{
    int n,w;
    cin>>n>>w;
    vector< int > a(n);
    REF dp(n,aray(w + 1,false));
    roop(i,n)cin>>a[i];
    dp[0][0] = dp[0][a[0]] = true;
    
    rep(i,1,n)
    {
        roop(j,w + 1)
        {
            int x = j;
            if(j - a[i] >= 0)x = j - a[i];
            dp[i][j] = dp[i - 1][j] | dp[i - 1][x];
        }
    }


    if(dp[n - 1][w])cout<<"Yes"<<endl;
    else cout<<"No"<<endl;


    return 0;
}