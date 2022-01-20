#include<iostream>
#include<algorithm>
#include<cmath>
#include<stdbool.h>
#include<climits>
#define rep(a,b,c) for(int a = b; a < c; a++)
using namespace std;

int main(void){
  int n;
     cin>>n;
     char alpha[n];
     int  number[n];
     char bubble[n];
     char select[n];
     int Ssort[n];
     rep(i,0,n){
         cin>>alpha[i]>>number[i];
         Ssort[i] = number[i];
     }
     
         
     strcpy(bubble,alpha);
     strcpy(select,alpha);
     
     /*selection sort*/
     int minj = INT_MAX;
     rep(i,0,n - 1){
         int minj = i;
        rep(j,i,n)if(Ssort[minj] > Ssort[j])minj = j;
        char c = select[minj];
        select[minj] = select[i];
        select[i] = c;
        int a = Ssort[i];
        Ssort[i] = Ssort[minj];
        Ssort[minj] = a;
     }
     rep(i,0,n)cout<<select[i]<<Ssort[i]<<" ";
     cout<<endl;
     





     /*bubble sort*/
     rep(i,0,n - 1){
         rep(j,0,n - i){
             if(number[n - 2 - j] > number[n-1-j]){
                 
                 int a = number[n-2-j];
                 number[n-2-j] = number[n-1-j];
                 number[n-1-j] = a;
                 char c = bubble[n-2-j];
                 bubble[n-2-j] = bubble[n-1-j];
                 bubble[n-1-j] = c;
    
             }
         }
     }
         rep(i,0,n)cout<<bubble[i]<<number[i]<<" ";
         cout<<endl;
         
         return 0;
     

}
