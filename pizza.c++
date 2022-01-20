#include<iostream>
using namespace std;
int main(void){
    long a, b, c;
    long x, y;
    cin>>a>>b>>c>>x>>y;
    int I,J,K;
    long long ans = 100000000000;
    for(long long k = 0 ; k <= 200000 ; k += 2){
        long long i = x - k / 2;
        long long j = y - k / 2;
        if(i < 0 )i = 0;
        if(j < 0 )j = 0;
        long long charge = a * i + b * j + c * k;
        if(ans > charge){
            
            ans = charge;
        }
    }
    cout<<ans<<endl;
    return 0;

    
}