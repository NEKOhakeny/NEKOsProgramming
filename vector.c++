#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<string>
#include<cstdio>
#define rep(a,b,c) for(int a = b ; a < c ; a++)
using namespace std;
int getnumber(char *,int *,int);
int main(void){
    int n;
    cin>>n;
    char number[n];
    cin>>number;
    int i = 0;
    int ans = getnumber(number,&i,n);
    cout<<ans<<endl;
    return 0;

}

int getnumber(char *literal,int *i,int num){
    int j = 0;
    char array[num];
    for(int j = 0; literal[j] != '\0' ; j++){
        array[j] = literal[*i];
        *i += 1;
    }
    cout<<array<<endl;
    int n = strlen(array);
    cout<<" strlen"<<endl;
    cout<<n<<endl;
    int sum = 0;
    rep(j,0,n){
        int a;
        cout<<array[n - 1 - j]<<endl;
        a = array[n - 1 - j] - '0';
        cout<<" a"<<endl;
        cout<<a<<endl;
        rep(k,0,j){
            a *= 10;
        }
        cout<<a<<endl;
        sum += a;    
    }
    
    return sum;
    
}

