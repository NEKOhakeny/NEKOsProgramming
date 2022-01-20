#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<string>
#include<cstdio>
#define N 5000
#define rep(a,b,c) for(int a = b ; a < c ; a++)
using namespace std;
int  stack[100];
int main(void){
    
    int head = 0;
    int head2 = 0;
    
    char array[200][10];
    char literal[N];
    int word = 0;
    fgets(literal,N,stdin);
    int j = 0;
    int k = 0;
    for(int i = 0; ; i++){
        if(literal[i] == ' '){
            k = 0;
            j++;
            continue;
        }
        array[j][k] = literal[i];
        k++;
        if(literal[i] == '\0')break;
    }
    cout<<j<<endl;
    rep(i,0,j+1){
        char c[10];
        strcpy(c,array[i]);
        char opeland[10];
        if(c[0] < '0' || c[0] >'9'){
            int ans;
            if(c[0] == '+')ans = stack[head - 2] + stack[head - 1];
            else if(c[0] == '-')ans = stack[head - 2] - stack[head - 1];
            else if(c[0] == '*')ans = stack[head - 2] * stack[head - 1];
            else if(c[0] == '/')ans = stack[head - 2] / stack[head - 1];
            stack[head - 2] = ans;
            head -= 1;
            head2 -= 1;
            
        }else {
            int num = atoi(c);
            stack[head] = num;
            head++;
        }
         
    }
    cout<<stack[head - 1]<<endl;

    return 0;
}

    
