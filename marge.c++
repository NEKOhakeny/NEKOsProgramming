#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<climits>
#define check cout<<"check"<<endl
#define rep(a,b,c)   for(int a = b ; a < c ;a++)
using namespace std;
int allcator(int *,int ,int,int);
int margediv(int *,int ,int);
int main(void){
    int n;
    cin>>n;
    int a[n];
    rep(i,0,n)cin>>a[i];
    int ans = margediv(a,0,n);
    rep(i,0,n){
        cout<<a[i];
        if(i != n - 1)cout<<" ";
    }
    cout<<endl;
    cout<<ans<<endl;
    return 0;
}
int margediv(int *a,int left,int right){
    static int ans = 0;
    if(right - left > 1){
        int mid = (left + right) / 2;
        margediv(a,left,mid);
        margediv(a,mid,right);
        ans = allcator(a,left,right,mid);
    }
    return ans;
    
    
}

int allcator(int *a,int left,int right,int mid){
    static int count = 0;
    int L = mid - left;
    int R = right - mid;
    int l[L+1];
    int r[R+1];
    rep(i,0,L)l[i] = a[left + i];
    rep(i,0,R)r[i] = a[mid + i];
    l[L] = INT_MAX;
    r[R] = INT_MAX;
    int i = 0;
    int j = 0;

    rep(k,left,right){
        count++;
        if(l[i] > r[j]){
            a[k] = r[j];
            j++;
        }else {
            a[k] = l[i];
            i++;
        }

    }
    
    return count;



}

