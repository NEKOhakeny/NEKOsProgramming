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
    struct node *parent = NULL;
}tree ;
int cmpnode(int,int,tree **,tree *);
void createnode(int, tree **,tree *);
void inorder(tree *);
/*void deletenode(tree *);
tree* searchright(tree *);
tree* searchleft(tree *);
 */
tree* head = NULL;
int main(void){
    int n;
    cin>>n;
    rep(i,0,n){
        string str;
        cin>>str;
        int m;
        cin>>m;
        if(str == "insert"){
            if(cmpnode(1,m,&head,NULL) == 0)cout<<"This key is exist."<<endl;
            
        }
        else if(str == "find"){
            int ans = cmpnode(0,m,&head,NULL);
            if(ans == 1){
                cout<<"no"<<endl;
            }
            else cout<<"yes"<<endl;
        }/*else if(str == "delete"){
            if(cmpnode(2,m,&head,NULL) == 1)cout<<"This key dose not exist."<<endl;
        }*/
        inorder(head);
        cout<<endl;
    }
    return 0;
}
int cmpnode(int i,int m,tree **PPnode,tree *Pnode){
    if((*PPnode) != NULL){
        if((*PPnode)->id > m) return cmpnode(i,m,&(*PPnode)->left,*PPnode);
        else if((*PPnode)->id == m){
            /*if( i == 2){
                deletenode(*PPnode);
                return 0;
            }
            else */return 0;
        }
        else return cmpnode(i,m,&(*PPnode)->right,*PPnode);
    }
    if(i != 1)return 1;
    createnode(m,PPnode,Pnode);
    //cout<<(*Pnode)->id<<endl;
    return 1;
}
void createnode(int m,tree **PPnode,tree *Pnode){
    (*PPnode) = (tree *)malloc(sizeof(tree));
    (*PPnode)->id = m;
    (*PPnode)->parent = Pnode;
    return ;
}
void inorder(tree *Pnode){
    if(Pnode->left != NULL)inorder(Pnode->left);
    cout<<" ";
    cout<<Pnode->id;
    if(Pnode->right != NULL)inorder(Pnode->right);
}
/*
void deletenode(tree *Pnode){
    if(Pnode->parent != NULL){
        int m = Pnode->parent->id;
        tree *node;
        tree **PPnode;
        if(m > Pnode->parent->id)(*PPnode) = Pnode->parent->right;
        else (*PPnode) = Pnode->parent->left;
        if(Pnode ->right != NULL) node = searchright(Pnode->right); 
        else if(Pnode-> left != NULL )node = searchleft(Pnode->left);
        else node = NULL;
        node->parent = Pnode->parent;
        (*PPnode) = node;
    }
    free(Pnode);
    return;
}

tree* serachright(tree *Pnode){
    if(Pnode->left !=  NULL)return searchright(Pnode->left);
    return Pnode;
}

tree* searchleft(tree *Pnode){
    if(Pnode->right != NULL)return searchleft(Pnode->right);
    return Pnode;
}
 */
