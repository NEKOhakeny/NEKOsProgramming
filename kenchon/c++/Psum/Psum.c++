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
#define INF 1000100100
using namespace std;
using REF = vector< vector<int> > ;
using aray = vector< int >;
using namespace std;

int main()
{
    int n,W;
    cin>>n>>W;
    aray v(n), w(n);
    rep(i,0,n)cin>>v[i]>>w[i];
    int max = 0;
    roop(bit,1 << n)
    {
        int tmp = 0;
        int val = 0;
        roop(j,n)
        {
            if(1 << j & bit){
                tmp += w[j];
                val += v[j];
            }
        }
        if(tmp > W)continue;
        if(val > max)max = val;
    }
    cout<<max<<endl;
    return 0;
}

