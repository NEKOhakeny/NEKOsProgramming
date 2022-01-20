#include<iostream>
using namespace std;
int main(void){
    int ans = 0;
    int N,x;
    cin>>N>>x;
    for(int i = 1; i < N ; i++){
        for(int j = i + 1 ; j < N ; j++){
            int k = x -i -j;
            if(k > j && k <= N){
                ans++;
            }
        }
    }
    cout<<ans <<endl;

    return 0;


}