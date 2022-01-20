#include<iostream>
#include<algorithm>
#include<cmath>
#include<climits>
#define rep(a,b,c) for(int a = b; a < c ;a++)
using namespace std;

int main(void) {
    int n;
    cin>>n;
    int number[n];
    rep(i,0,n)cin>>number[i];
    int count = 0;
    /*selection sort*/
     int minj = INT_MAX;
     rep(i,0,n - 1){
         int minj = i;
        rep(j,i+1,n)if(number[minj] > number[j])minj = j;
        if(minj != i){
            int a = number[i];
            number[i] = number[minj];
            number[minj] = a;
            count++;
        }
        
     }
    
     
     rep(i,0,n){
         cout<<number[i];
         if(i != n - 1)cout<<" ";
     }
     cout<<endl;
     cout<<count<<endl;
    
     return 0;

}