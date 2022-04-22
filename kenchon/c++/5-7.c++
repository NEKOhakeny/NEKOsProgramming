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

template <class T> void chmax(T & a,T b){
    if(a < b)a = b;
}

int main()
{
    string s1;
    string s2;
    cin>>s1;
    cin>>s2;
    int s = s1.length();
    int t = s2.length();
    REF dp(s + 1,aray(t + 1,0));
    REF state(s + 1,aray(t + 1,0));
    rep(i,1,s + 1)
    {
        rep(j,1,t + 1)
        {
            if(s1[i - 1] == s2[j - 1])
            {
                chmax(dp[i][j],dp[i - 1][j - 1] + 1);
                continue;
            }
            dp[i][j] = max(dp[i - 1][j],dp[i][j - 1]);
        }
    }

    roop(i,s + 1)
    {
        roop(j,t + 1)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;

}

