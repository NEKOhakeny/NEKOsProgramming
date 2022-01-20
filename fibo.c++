#include<iostream>
#include<algorithm>
#include<string>
#include <vector>
#include <climits>
#define check cout<<"check"<<endl
using namespace std;			
#define rep(a,b,c) for(int a = b; a < c; a++)
int calcfibo(int ,int *);


int main(void){
    int n;
    cin>>n;
    int judge[n + 1];
    rep(i,0,n + 1)judge[i] = 0;
    int ans = calcfibo(n,judge);
    cout<<ans<<endl;
    return 0;
}

int calcfibo(int n,int *judge){
    if(n == 1 || n == 0)return 1;
    if(judge[n] != 0)return judge[n];
    int ans = calcfibo(n - 1,judge) + calcfibo(n - 2,judge);
    judge[n] = ans;
    /*cout<<"n = "<<n<<endl;
    cout<<"a(n) = "<<ans<<endl;
    */
    return ans;
}


