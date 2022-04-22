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
template<class T> void chmin(T &a,T b)
{
    if(a > b)a = b;
}

int main(void)
{
    string S,T;
    cin>>S>>T;
    int s = S.length() + 1;
    int t = T.length() + 1;
    REF dp(s,aray(t,INT_MAX));
    dp[0][0] = 0;
    roop(i,s)
    {
        roop(j,t)
        {
            if(i != 0)chmin(dp[i][j],dp[i - 1][j] + 1);
            if(j != 0)chmin(dp[i][j],dp[i][j - 1] + 1);
            if(i != 0 && j != 0){
                if(S[i - 1] == T[j - 1])chmin(dp[i][j],dp[i - 1][j - 1]);
                else chmin(dp[i][j],dp[i - 1][j - 1] + 1);
            }
            
        }
    }
    
    return 0;

    
}