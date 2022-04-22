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

int main(void)
{
    int n,w,k;
    cin>>n>>w>>k;
    aray a(n);
    REF dp(n,aray(w + 1,INF));
    roop(i,n)cin>>a[i];
    roop(i,n)dp[i][0] = 0;
    dp[0][a[0]] = 1;
    rep(i,1,n)
    {
        roop(j,w + 1)
        {
            dp[i][j] = dp[i - 1][j];
            int x = j - a[i];
            if(x < 0)continue;
            chmin(dp[i][j],dp[i - 1][x] + 1);
        }

    }
    /*roop(i,n)
    {
        roop(j,w + 1)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    */
    if(dp[n - 1][w] <= k)cout<<"true";

    else cout<<"false";

    cout<<endl;

    return 0;

}