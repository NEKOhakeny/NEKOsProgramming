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
    int degree;
    int leng;
    int height;
    int type;
    struct binary *oya;
    struct binary *right;
    struct binary *left;
    struct binary *bro;
}tree;
void maketree(tree **,int);
int typeinf(tree *);
int getheight(tree *);
int MAX = 0;
int main(void){
    int n;
    cin>>n;
    tree* node[n];
    rep(i,0,n){
        node[i] = (tree *)malloc(sizeof(tree));
        int leng;
        node[i]->Key = i;
        node[i]->oya = NULL;
        node[i]->right = NULL;
        node[i]->left = NULL;
        node[i]->bro = NULL;
    }
    rep(i,0,n){
        int id;
        cin>>id;
        maketree(node,id);
    }
    rep(i,0,n){
        node[i]->type = typeinf(node[i]);
    }
    
    rep(i,0,n){
        //cout<<node[i]->Key;
        //cout<<endl;
        int count = 0;
        for(tree* p = node[i]; p->oya != NULL; p = p->oya)count++;
        if(node[i])
        node[i]->degree = count;
        //cout<<count<<endl;
        if(MAX < count)MAX = count;
        //cout<<node[i]->Key;
        //cout<<endl;
    }
    //rep(i,0,n)cout<<node[i]->Key<<endl;
    //cout<<MAX<<endl;
    
    rep(i,0,n){
        cout<<"node ";
        //cout<<i<<endl;
        cout<<node[i]->Key<<":";
        cout<<" parent = ";
        if(node[i]->type != 0){
            cout<<node[i]->oya->Key;
        }else cout<<"-1";
        cout<<", sibling = ";
        if(node[i]->type != 0){
            if(node[i]->oya->leng == 2){
                cout<<node[i]->bro->Key;
            }
            else cout<<"-1";
        }else cout<<"-1";
        cout<<", degree = ";
        cout<<node[i]->leng;
        cout<<", depth = ";
        cout<<node[i]->degree;
        cout<<", height = ";
        cout<<node[i]->height;
        if(node[i]->type == 0)cout<<", root";
        else if(node[i]->type == 1)cout<<", leaf";
        else if(node[i]->type == 2)cout<<", internal node";
        cout<<endl;
    }
    
    
    

    return 0;
}
int  getheight(tree* node){
    int r,l;
    if(node->left != NULL)l = getheight(node->left) + 1;
    else l = 0;
    if(node->right != NULL)r = getheight(node->right) + 1;
    else r = 0;
    node->height = max(r,l);
    /*
    cout<<r<<endl;
    cout<<l<<endl;
    cout<<"node = ";
    cout<<node->Key<<endl;
    cout<<"height = ";
    cout<<node->height<<endl;
    */
    
    return node->height;

}
void maketree(tree* *node,int id){
    int R,L;
    cin>>R;
    cin>>L;
    int ko = 0;
    if(R != -1){
        node[id]->right = node[R];
        node[R]->oya = node[id];
        ko++;
    }
    if(L != -1){
        node[id]->left = node[L];
        node[L]->oya = node[id];
        ko++;
    }
    if(ko == 2){
        node[id]->right->bro = node[id]->left;
        node[id]->left->bro = node[id]->right;
    }
    node[id]->leng = ko;
    //if(node[id]->right != NULL)cout<<node[id]->right->Key<<endl;
    //if(node[id]->left != NULL)cout<<node[id]->left->Key<<endl;

    return;
}
int typeinf(tree *node){
    if(node->oya == NULL){
        getheight(node);
        return 0;
    }
    else if(node->right == NULL && node->left == NULL)return 1;
    else return 2;


}
