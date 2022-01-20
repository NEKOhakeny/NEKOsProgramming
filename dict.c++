#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include <vector>
#include <climits>
#define check cout<<"check"<<endl
using namespace std;			
#define rep(a,b,c) for(int a = b; a < c; a++)

int s2h(char );
typedef struct node{
    int num[13] = {0,0,0,0,0,0,0,0,0,0,0,0,0};
    struct node *next;
} dict;
dict *Dnode = NULL;
void defdict(char *,dict **,int);
int findword(char *,dict **,int);
int main(void){
    int n;
    cin>>n;
    rep(i,0,n){
        string order;
        cin>>order;
        char str[12];
        cin>>str;
        int leng = strlen(str);
        if(order == "insert"){
            defdict(str,&Dnode,leng);
        }
        else{
            int judge = findword(str,&Dnode,leng);
            if(judge == 1)cout<<"yes"<<endl;
            else cout<<"no"<<endl;
        }
    }

    return 0;
}


int s2h(char c){
    switch(c){
        case 'A':
            return 1;
            break;
        case 'C':
            return 2;
            break;
        case 'G':
            return 3;
            break;
        case 'T':
            return 4;
            break;
            default:
            return 0;
            break;    
    }
}

void defdict(char *str,dict **Pnode,int leng){
    static int i = 0;
    int m = s2h(str[i]);
    //cout<<m<<endl;
    //cout<<leng<<endl;
    i++;
    if((*Pnode) == NULL){
        (*Pnode) = (dict *)malloc(sizeof(dict) * 5);    
    }
    
    (*Pnode)[m].num[leng] = 1;
   /*cout<<"m = "<<m<<endl;
    cout<<"leng = "<<leng<<endl;
    cout<<(*Pnode)[m].num[leng]<<endl;
    */
    if(i == leng){
        i = 0;
        return;
    }
    defdict(str,&(*Pnode)[m].next,leng);
    
}
int findword(char *str,dict **Pnode,int leng){
    if((*Pnode) == NULL)return 0;
    static int i = 0;
    int m = s2h(str[i]);
    i++;
    if((*Pnode)[m].num[leng] == 0){
        i = 0;
        return 0;
    }
    else {
        if(i == leng  || findword(str,&(*Pnode)[m].next,leng) == 1){
            i = 0;
            return 1;        
        }
    }
}
