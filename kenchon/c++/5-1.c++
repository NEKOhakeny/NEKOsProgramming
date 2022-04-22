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
#define N 100000
using namespace std;
using sque = vector< vector<int> > ;
using aray = vector< int >;
using namespace std;

sque value(N,aray(3));
sque dp(N,aray(3,0));
template<class T> T MAX(int x,int i)
{
    if(i == 0)return 0;
    int y,z;
    y = (x + 1) % 3;
    z = (x + 2) % 3;
    return max(dp[i - 1][y],dp[i - 1][z]);
}
int main(void)
{
    int n;
    cin>>n;
    roop(i,n)roop(j,3)cin>>value[i][j];
    roop(i,n)
    {
        roop(j,3)
        {
            dp[i][j] = MAX<int>(j,i) + value[i][j];
        }
    }
    int max = 0;
    for(auto g : dp[n - 1])
    {
        if(max < g)max = g;
    }
    cout<<max<<endl;
    return 0;
}