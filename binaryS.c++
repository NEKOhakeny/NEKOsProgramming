#include<iostream>
#include<algorithm>
#include<string>
#include <vector>
#include <climits>
#define check cout<<"check"<<endl
using namespace std;			
#define rep(a,b,c) for(int a = b; a < c; a++)

typedef struct binary{
    int Key;
    struct binary *oya;
    struct binary *right;
    struct binary *left;
}tree;

void compNode(int,tree *);
void makeNode(int,tree **,tree *);
void println(tree *,int );
void println2(tree *,int);

tree *head = NULL;

int main(void){
    int n;
    cin>>n;
    rep(i,0,n){
        static int j = 0;
        //cout<<j<<endl;
        int num;
        string order;
        cin>>order;
        //check;
        if(order == "insert"){
            cin>>num;
            if(head != NULL)compNode(num,head);
            else makeNode(num,&head,NULL);
            j++;
            //cout<<head->Key<<endl;
        }
        else if(order == "print"){
            println(head,j);
            println2(head,j);
        }
    }
    return 0;
}
void compNode(int num,tree *node){
    if(num > node->Key){
        if(node->right != NULL)compNode(num,node->right);
        else makeNode(num,&node->right,node);
        //cout<<node->right->Key<<endl;
    }
    else {
        if(node->left != NULL)compNode(num,node->left);
        else makeNode(num,&node->left,node);
       // cout<<node->left->Key<<endl;
    }
}

void makeNode(int num,tree * *node,tree *pre){
    *node = (tree *)malloc(sizeof(tree));
    (*node)->Key = num;
    (*node)->left = NULL;
    (*node)->right = NULL;
    (*node)->oya = pre;
}

void println(tree *node,int n){
    static int i = 0;
    if(node->left != NULL)println(node->left,n);
    cout<<" ";
    cout<<node->Key;
    i++;
    if(i == n){
        cout<<endl;
        i = 0;
    }
    if(node->right != NULL)println(node->right,n);
    return;
}

void println2(tree* node,int n){
    static int i = 0;
    cout<<" ";
    cout<<node->Key;
    i++;
    if(i == n){
        cout<<endl;
        i = 0;
    }
    if(node->left != NULL)println2(node->left,n);
    if(node->right != NULL)println2(node->right,n);
    return;
}


