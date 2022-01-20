#include<iostream>
#include<algorithm>
#include<string>
#include <vector>
#define check cout<<"check"<<endl
#define rep(a,b,c) for(int a = b; a < c ;a++)
using namespace std;
void insert_x(int);
int delete_x(int);
void deleteFirst();
void deleteLast();
void println();
typedef struct key{
    int number;
    struct key *pre;
    struct key *next;
} tree;
tree *head = NULL;
tree *tail = NULL;
int  main(void){
    int n;
    cin>>n;
    rep(i,0,n){
        string order;
        cin>>order;
        int num;
        if(order == "deleteFirst")deleteFirst();    
        else if(order == "deleteLast")deleteLast();
        else{
            cin>>num;
            if(order == "insert")insert_x(num);          
            else if(order =="delete")delete_x(num);
        }
        /*cout<<endl;
        cout<<order<<" ";
        cout<<num<<endl;
        println();
        */
        
    }
    println();
}
void insert_x(int num){
   
    tree *n;
    n = (tree *)malloc(sizeof(tree));
    n->number = num;
    if(head != NULL){
        n->next = head;
        head->pre = n;
    }
    else {
        n->next = NULL;
        tail = n;
    }
    n->pre = NULL;
    head = n;
}
int delete_x(int num){
    tree *n;
    if(num == head->number){
        deleteFirst();
        return 1;
    }
    for(n = head; n != NULL ; n = n->next){
        if(n->number == num){
            if(n->next != NULL){
            n->pre->next = n->next;
            n->next->pre = n->pre;
            free(n);
            }else deleteLast();
            return 1;
        }
    }
    return 0;
}
    
void deleteFirst(void){
    if(head->next != NULL)head = head->next;
    else {
        free(head);
        head =NULL;
        tail = NULL;
        return;
    }
    free(head->pre);
    head->pre = NULL;
}

void deleteLast(void){
    if(tail->pre != NULL)tail = tail -> pre;
    else {
        free(tail);
        tail = NULL;
        head = NULL;
        return;
    }
    free(tail->next);
    tail->next = NULL;
}

void println(void){
    
    for(tree *n = head ; n != NULL ; n = n->next){
        cout<<n->number;
        if(n->next != NULL)cout<<" ";
    }
    cout<<endl;
}