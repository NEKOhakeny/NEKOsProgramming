#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
using namespace std;
#define rep(a,b,c)   for(int a = b ; a < c ;a++)

typedef struct node{
    int id;
    struct node *right = NULL;
    struct node *left = NULL;
    struct node *parent = NULL;
}tree;
void makenode(int,tree *);
void preorder(tree *);
void inorder(tree *);
void postorder(tree *);
tree *head = NULL;
int main(void){
    int n;
    cin>>n;
    tree *Pnode = (tree *)malloc(sizeof(tree ) * n);
    rep(i,0,n)Pnode[i].id = i;
    rep(i,0,n){
        int num;
        cin>>num;
        makenode(num,Pnode);
    }
    rep(i,0,n){
        if(Pnode[i].parent != NULL)continue;
        head = &Pnode[i];

    }
    cout<<"Preorder"<<endl;
    preorder(head);
    cout<<endl;
    cout<<"Inorder"<<endl;
    inorder(head);
    cout<<endl;
    cout<<"Postorder"<<endl;
    postorder(head);
    cout<<endl;
    return 0;
}
void makenode(int num,tree *Pnode){
    int r,l;

    cin>>l;
    cin>>r;
    if(r != - 1){
        Pnode[num].right = &Pnode[r];
        Pnode[num].right->parent = &Pnode[num];
    }
    if(l != - 1){
        Pnode[num].left = &Pnode[l];
        Pnode[num].left->parent = &Pnode[num];
    }
    /*
    cout<<head[num].id<<endl;
    cout<<"left = ";
    if(l != - 1)cout<<head[num].left->id<<endl;
    else cout<<" - 1"<<endl;
    cout<<"right = ";
    if(r != -1)cout<<head[num].right->id<<endl;
    else cout<<" - 1"<<endl;
    */
}
void preorder(tree *Pnode){
    cout<<" ";
    cout<<Pnode->id;
    if(Pnode->left != NULL)preorder(Pnode->left);
    if(Pnode->right != NULL)preorder(Pnode->right);
}
void inorder(tree *Pnode){
    if(Pnode->left != NULL)inorder(Pnode->left);
    cout<<" ";
    cout<<Pnode->id;
    if(Pnode->right != NULL)inorder(Pnode->right);
}
void postorder(tree *Pnode){
    if(Pnode->left != NULL)postorder(Pnode->left);
    if(Pnode->right != NULL)postorder(Pnode->right);
    cout<<" ";
    cout<<Pnode->id;


}

