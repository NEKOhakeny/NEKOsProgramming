#include<iostream>
#include<cmath>
#define rep(a,b,c) for(int a = b ; a < c; a++)
using namespace std;

int main(void){
    int n;
    cin>>n;
    int number;
    rep(i,0,n){
        cin>>number;
        int count = 0;
        rep(j,2,number + 1){
            int product = 1;
            rep(k,2,j/2 + 1){
                if(j % k == 0)product *= k;
            }
            if(product >= j * 2)count++;
        }
        cout<<"count:"<<count<<" number:"<<number<<endl;


    }
    return 0;
    

}
    