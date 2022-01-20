#include<iostream>
using namespace std;

bool judgement(int charge){
    double min = 100000;
    int i = 1;
    while(1){
        double ave = (double)charge / (double)i;
        if(ave < 100)break;
        min = ave;
        i++;
    }
    if(min <= 105)return true;
    else return false;
}

int main(void){
    int N;
    cin>>N;
    if(judgement(N) == true )cout<<1<<endl;
    else cout<<0<<endl;
    return 0;
    
    
}