#include<iostream>
#include<algorithm>
#include<string>
#include <vector>
#include <climits>
#define check cout<<"check"<<endl
using namespace std;			
#define rep(a,b,c) for(int a = b; a < c; a++)
typedef struct node{
    int id;
    struct node *left  = NULL;
    struct node *right = NULL;
}tree ;
tree *  createnode(tree *);
tree *head = NULL;
int main(void){
    int n;
    cin>>n;
    head = (tree *)malloc(sizeof(tree) * n);
    int num[n];
    rep(i,0,n){
        cin>>num[i];
    }
    sort(num,num + n);
    rep(i,0,n)head[i].id = num[i];
}
tree * createnode(tree *head){
    
}
