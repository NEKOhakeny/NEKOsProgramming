#include<iostream>
#include<string>
#define rep(a,b,c) for(int a = b ; a < c; a++)
using namespace std;

struct cube{
  int ans;
  int x[2],y[2],z[2];
  int  combination(string a){
    int *b;
        int *c;
        rep(i,0,a.length()){
	  if(a[i] == 'E'){
	    b = &z[1];
	    c = &z[0];
	  }
	  if(a[i] == 'W'){
	    b = &z[0];
	    c = &z[1];
	  }
	  if(a[i] == 'N'){
	    b = &y[0];
	    c = &y[1];
	  }
	  if(a[i] == 'S'){
	    b = &y[1];
	    c = &y[0];
	  }
	  ans = translation(b,c);
	  
        }
        return ans;
  }  
  int translation(int *d,int *e){
    int a;
    a = x[0];
    x[0] = *d;
    *d = x[1];
    x[1] = *e;
    *e = a;
    return x[0];
  }
  int side2side(){
    int a;
    a = y[0];
    y[0] = z[0];
    z[0] = y[1];
    y[1] = z[1];
    z[1] = a;        
    return y[0];
  }
  
};

int main(void){
  struct cube dice;
  
  cin>>dice.x[0]>>dice.y[0]>>dice.z[0];
  cin>>dice.z[1]>>dice.y[1]>>dice.x[1];
  int n;
  cin>>n;
  int upper[n],flont[n];
  rep(i,0,n){
    cin>>upper[i]>>flont[i];
    int judge = 0;
    while(1){
      judge = dice.side2side();
      if(flont[i] == judge)break;
    }
    
    while(1){
      judge = dice.combination("W");
      if(upper[i] == judge )break;
    }
        cout<<dice.z[0]<<endl;
  }
  return 0;
  
}
