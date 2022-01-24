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

//ノードを探索する関数
int cmpnode(int,int,tree **,tree *);

//新しいノードを作る関数
void createnode(int, tree **,tree *);

//ノードの削除に関連する関数
void deletenode(tree *);
void cmpnode2(tree **);
tree* searchright(tree *);
tree* searchleft(tree *);
void deleteright(tree *);
void deleteleft(tree *);

//ノードを出力する関数
void preorder(tree *);
void inorder(tree *);
void postorder(tree *);
void println(tree *);

//先頭のノードポインタ
tree* head = NULL;


int main(void){
    int n;
    cin>>n;
    rep(i,0,n){
        string str;
        cin>>str;
        if(str == "print"){
            println(head);
            continue;
        }
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
        }else if(str == "delete"){
            if(cmpnode(2,m,&head,NULL) == 1)cout<<"This key dose not exist."<<endl;
        }
        preorder(head);
        cout<<endl;
    }
    return 0;

}


//ノードを探索する関数
int cmpnode(int i,int m,tree **PPnode,tree *Pnode){
    if((*PPnode) != NULL){
        if((*PPnode)->id > m) return cmpnode(i,m,&(*PPnode)->left,*PPnode);
        else if((*PPnode)->id == m){
            if( i == 2){
                //cout<<"node";
                //cout<<(*PPnode)->id<<endl;
                deletenode(*PPnode);
                return 0;
            }
            else return 0;
        }
        else return cmpnode(i,m,&(*PPnode)->right,*PPnode);
    }
    if(i != 1)return 1;
    createnode(m,PPnode,Pnode);
    //cout<<(*Pnode)->id<<endl;
    return 1;
}

//新しいノードを作る
void createnode(int m,tree **PPnode,tree *Pnode){
    (*PPnode) = (tree *)malloc(sizeof(tree));
    (*PPnode)->id = m;
    (*PPnode)->parent = Pnode;
    return ;
}


//ノードの削除に関する
void deletenode(tree *Pnode){
    check;
    if(Pnode->right != NULL)deleteright(Pnode);
    else if(Pnode->left != NULL)deleteleft(Pnode);
    else {
        check;
        if(Pnode->parent != NULL)cmpnode2(&Pnode);
        free(Pnode);
    }
    

}


void cmpnode2(tree **Pnode){
    //cout<<"clear"<<endl;
    cout<<(*Pnode)->id<<endl;
    int m = (*Pnode)->parent->id;
    cout<<m<<endl;
    if(m > (*Pnode)->id){
        (*Pnode)->parent->left = NULL;
    }
    else (*Pnode)->parent->right = NULL;
    check;
    
}



void deleteright(tree * Pnode){
    check;
    if(Pnode->right == NULL){
        cmpnode2(&Pnode);
        free(Pnode);
        return;
    }
    tree *newkey = searchright(Pnode->right);
    Pnode->id = newkey->id;
    deleteright(newkey);
}
void deleteleft(tree *Pnode){
    //check;
    if(Pnode->left == NULL){
        cmpnode2(&Pnode);
        free(Pnode);
        return;
    }
    tree *newkey = searchleft(Pnode->left);
    Pnode->id = newkey->id;
    deleteleft(newkey);
}




tree*  searchright(tree *Pnode){
    //cout<<Pnode->id<<endl;
    if(Pnode->left !=  NULL)return searchright(Pnode->left);
    //cout<<Pnode->id<<endl;
    return Pnode;
}
tree* searchleft(tree *Pnode){
    //cout<<Pnode->id<<endl;
    if(Pnode->right != NULL)return searchleft(Pnode->right);
    //cout<<Pnode->id<<endl;
    return Pnode;
}
 
 //出力関数

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
void println(tree *head){
    inorder(head);
    cout<<endl;
    preorder(head);
    cout<<endl;
    
    return ;
}

