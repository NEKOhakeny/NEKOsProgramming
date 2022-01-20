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
    struct node *left;
    struct node *right;
    struct node *parent;

}tree;
void makenode (int **,tree **,int,tree *,int);
int main(void){
    int n;
    cin>>n;
    tree *head[2 * n + 2];
    rep(i,0,n){
        head[i + 1] = (tree *)malloc(sizeof(tree));
        head[i + 1]->left = NULL;
        head[i + 1]->right =  NULL;
        head[i + 1]->parent = NULL;

    }
    rep(i,n + 1,2 * n + 2)head[i] = NULL; 
    int *array = (int *)malloc(sizeof(int) * n);
    rep(i,0,n)cin>>array[i + 1];
    //check;
    makenode(&array,head,1,NULL,n + 1);
    rep(i,0,n){
        cout<<"node ";
        cout<<i + 1<<": ";
        cout<<"key = ";
        cout<<head[i + 1]->id;
        cout<<", ";
        if(head[i + 1]->parent != NULL){
            cout<<"parent key = ";
            cout<<head[i + 1]->parent->id;
            cout<<", ";
        }
        if(head[i + 1]->left != NULL){
            cout<<"left key = ";
            cout<<head[i + 1]->left->id;
            cout<<", ";
        }
        if(head[i + 1]->right != NULL){
            cout<<"right key = ";
            cout<<head[i + 1]->right->id;
            cout<<", ";
        }
        cout<<endl;
    }

    return 0;
}

void makenode(int * *a,tree **pnode,int i,tree *oya,int n){
    if(i > n)return;
    pnode[i]->id = (*a)[i];
    pnode[i]->parent = oya;
    pnode[i]->left = pnode[2 * i];
    pnode[i]->right = pnode[2 * i + 1];
    if(pnode[2 * i] != NULL)makenode(a,pnode,2 * i ,pnode[i],n);
    if(pnode[2 * i + 1] != NULL)makenode(a,pnode,2 * i + 1,pnode[i],n);
    return;

}


