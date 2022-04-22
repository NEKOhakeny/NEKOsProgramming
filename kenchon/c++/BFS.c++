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
using graph = vector< vector< int > > ;
using aray = vector< int >;
using namespace std;

int main()
{
    int n;
    cin>>n;
    aray depth(n,0);
    aray par(n,0);
    queue<int> node;
    graph G(n);
    roop(i,n)
    {
        int u,k;
        cin>>u>>k;
        roop(j,k)
        {
            int m;
            cin>>m;
            G[u - 1].push_back(m - 1);
            par[m - 1] = u - 1;
        }
    }
    node.push(0);
    depth[0] = 0;
    roop(i,n)cout<<par[i]<<" ";
    cout<<endl;
    while(!node.empty()){
        int m = node.front();
        node.pop();
        for(auto g : G[m])
        {
            node.push(g);
            cout<<g<<" ";
            //cout<<par[g]<<" ";
            depth[g] = depth[par[g]] + 1 ;
        }
        cout<<endl;
    }
    /*
    for(auto g : depth)
    {
        cout<<g<<endl;
    }
    */
    return 0;



}