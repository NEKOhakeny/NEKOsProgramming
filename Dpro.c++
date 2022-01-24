#include<iostream>
#include<algorithm>
#include<string>
#include <vector>
#include <climits>
#define check cout<<"check"<<endl
using namespace std;			
#define rep(a,b,c) for(int a = b; a < c; a++)
int a(int **,int *[2],int,int);
int Rcost(int,int,int);
int main(void){
    int n;
    cin>>n;
    int *det[n];

    int *cost[n];
    rep(i,0,n){
        det[i] = (int *)malloc(sizeof(int) * 2);
        cin>>det[i][0]>>det[i][1];
        cost[i] = (int *)malloc(sizeof(int) * n);
        rep(j,0,n)det[i][j] = 0;
        det[i][i] = -1;
        check;
        if(i != n - 1)det[i][i + 1] = Rcost(det[i][0],det[i][1],det[i + 1][1]);
    }
    int ans = a(cost,det,0,n - 1);
    cout<<ans<<endl;
    return 0;
}

int a(int **cost,int **det,int head,int tail){
    if(cost[head][tail] != 0)return cost[head][tail];
    return min(a(cost,det,head,tail - 1) + Rcost(det[head][0],det[tail][0],det[tail][1]),a(cost,det,head + 1,tail) + Rcost(det[head][0],det[head][1],det[tail][1]));
}

int Rcost(int a,int b,int c){
    return a * b * c;
}





