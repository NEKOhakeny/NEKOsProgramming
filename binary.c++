#include<iostream>
#include<climits>
#include<cstdio>
#include<algorithm>
#include<cstdio>
#define rep(a,b,c) for(int a = b; a < c ;a++)
int loop(int,int,int);
using namespace std;
void insort(int *,int);
int binary(int *,int ,int *,int);
int main(void){
  int n;
  cin>>n;
  int s[n];
  rep(i,0,n)cin>>s[i];
  int q;
  cin>>q;
  int t[q];
  rep(i,0,q)cin>>t[i];
  insort(s,n);
  cout<<binary(s,n,t,q)<<endl;
  return 0;

}
void insort(int *s,int n){
  rep(i,0,n - 1){
    int min = s[i+1];
    int j = i;  
    while(s[j] > min && j >= 0){
      s[j+1] = s[j];
      j -- ;
    }
    s[j + 1] = min;
  }
  return;
}


int binary(int *s,int n,int *t,int q){
  
  int count = 0;
  rep(i,0,q){
    int max = n - 1;
    int min = 0;
    
    if(s[max] < t[i] || s[min] > t[i])continue;
    while(max >= min){
      int mid = (max + min) / 2;
      if(s[mid] >= t[i])
        max = mid - 1;
      else if(s[mid] < t[i])min = mid + 1;
      else{
        count++;
        break;
      }
      
     
    }
      

  }
  return count;
}
