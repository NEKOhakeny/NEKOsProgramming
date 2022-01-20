#include<iostream>
#define rep(a,b,c) for(int a = b ; a < c ; a++)
using namespace std;

int main(void){
  int n,m;
  cin>>n>>m;
  int det[n][m];
  rep(i,0,n){
    rep(j,0,m)cin>>det[i][j];
  }
  int judge = 0;
  rep(i,0,n-1){
    rep(j,0,m-1){
      int tate = det[i + 1][j] - det[i][j];
      int yoko = det[i][j + 1] - det[i][j];
      if(yoko != 1 || tate !=7){
        judge = 1;
        break;
      }
    }
    if(judge == 1)break;
  }
  if(judge == 1)cout<<"No"<<endl;
  else cout<<"Yes"<<endl;
  

  return 0;
}
