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
    cin>>n;
    aray a(n);
    roop(i,n)cin>>a[i];
    int min = INT_MAX;
    int max = INT_MIN;
    for(auto g : a){
        if(max < g)max = g;
        if(min > g)min = g;
    }
    cout<<max - min<<endl;
    return 0;
}