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
    int leng;
    int degree;
    struct node *kodomo;
    struct node *oya;
}tree;
tree *node = NULL;
void createNode(int );
void defnode(int );
int main(void){
    int n;
    cin>>n;
    createNode(n);
    rep(i,0,n){
        int Key;
        cin>>Key;
        defnode(Key);
    }
    rep(i,0,n){
        int type = -1;
        cout<<"node ";
        cout<<node[i].id<<": ";
        cout<<"parent = ";
        if(node[i].oya != NULL)cout<<node[i].oya->id<<", ";
        else {
            type = 0;
            cout<<"-1"<<", ";
        }
        int depth  = 0;
        tree *p;
        for(p = &node[i]; p->oya != NULL; p = p->oya)depth++;
        node[i].degree = depth;
        cout<<"depth = ";
        cout<<node[i].degree<<", ";
        if(type == 0)cout<<"root, ";
        int length = node[i].leng;
        if(type != 0){
            if(length != 0)cout<<"internal node, ";
            else cout<<"leaf, ";
        }
        cout<<"[";  
       if(length != 0)rep(j,0,length){
           cout<<node[i].kodomo[j].id;
           if(j != length - 1)cout<<", ";
       }
       cout<<"]";
        cout<<endl;
    }
}
void createNode(int n){
    node = (tree *)malloc(sizeof(tree) * n);
    rep(i,0,n){
        node[i].id = i;
        node[i].kodomo = NULL;
        node[i].oya = NULL;
    }
    return;
}
void defnode(int Key){

    int n;
    cin>>n;
    node[Key].leng = n;
    node[Key].kodomo = (tree *)malloc(sizeof(tree) * n);
    rep(i,0,n){
        int id;
        cin>>id;
        node[id].oya = &node[Key];
        node[Key].kodomo[i] = node[id];
    
    }
    /*cout<<node[Key].degree<<" ";
    rep(j,0,n){
        cout<<node[Key].kodomo[j].id<<" ";
    }
    */
    return ;
}