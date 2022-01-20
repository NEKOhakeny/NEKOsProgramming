#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
using namespace std;
#define rep(a,b,c)   for(int a = b ; a < c ;a++)

int main(void){
    int stack[5];
    int head = 0;
    string literal;
    cin>>literal;
    while(1){
        int num;
        int sum;
        static int i = 0;
        if(literal[i] == '\n')break;
        char number[10];
        int j = 0;
        if(literal[i] >= '0' && literal[i] <= '9'){
            while(literal[i] != '\0'){
                number[j] = literal[i];
                i++;
                j++;
            }
            sum = 0;
            rep(k,0,j){
                num += number[j - i - 1] - '0';
                rep(l,0,j)num *= 10;
                sum += num;
            }
            cout<<sum<<endl;
            stack[head] += sum;
        }
        else {
            if(literal[i] == '+'){
                stack[head - 1] += stack[head];
            }
            if(literal[i] == '-'){
                stack[head - 1] -= stack[head];
            }
            if(literal[i] == '*'){
                stack[head - 1] *= stack[head];
            }
            if(literal[i] == '/'){
                stack[head - 1] /= stack[head];
            }
            head -= 1;
            i++;
        }
        head++;
    }
    cout<<stack[0]<<endl;
    return 0;
        

}
