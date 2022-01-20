#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<string>
#include<cstdio>
#define rep(a,b,c) for(int a = b ; a < c ; a++)
using  namespace std;
int main(void){
  int n;
  cin>>n;
  string literal;
  rep(i,0,n){
    string manip;
    cin>>manip;
    string str;
      cin>>str;
    if(manip == "insert"){
      literal += str;
    }else if(manip == "find"){
      int m = literal.length();
      int j = 0;
      int judge = 0;
      rep(i,0,m){
        if(str[j] == literal[i]){
          if(j == manip.length()){
            judge = 1;
            break;
            j++;
          }
        }
      }
      if(judge == 1)cout<<"yes"<<endl;
      else cout<<"no"<<endl;
    }
  }
  return 0;
}
