#include<iostream>
#include<algorithm>
#include<string>
#include <vector>
#include <climits>
#define check cout<<"check"<<endl
using namespace std;			
#define rep(a,b,c) for(int a = b; a < c; a++)
void pointer(int **);
int main(void){
    int *i;
    
    pointer(&i);
    cout<<*i<<endl;
    return 0;
    
}
void pointer(int * *pi){
    int a;
    *pi = (int *)malloc(sizeof(int));
    cin>>a;
    **pi = a;
    return;

}