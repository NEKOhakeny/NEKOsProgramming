#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<climits>
#define check cout<<"check"<<endl
#define rep(a,b,c)   for(int a = b ; a < c ;a++)
using namespace std;
typedef struct node{
  int id;
  struct node *next[4];
}dict;
node *head[4];
int* W2Hallocator(string,int);
void insert(int *,node **);
int main(void){
  int n;
  cin>>n;
  rep(i,0,n){
    string str;
    cin>>str;
    string word;
    cin>>word;
    int size = word.length();
    int *p = W2Hallocator(word,size);
    if(str == "insert")insert(p,head[]);
  }
}
int*  W2Hallocator(string word,int size){
  int a[size];
  rep(i,0,size){
    if(word[i] == 'A')a[i] = 0;
    else if(word[i] == 'C')a[i] = 1;
    else if(word[i] == 'T')a[i] = 2;
    else if(word[i] == 'G')a[i] = 3;
  }
  return a;
}
void insert(int *p,node **n){
  static int i = 0;
}


