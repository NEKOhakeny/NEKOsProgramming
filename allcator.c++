#include<iostream>
#include<algorithm>
#include<string>
#include <vector>
#define rep(a,b,c) for(int a = b; a < c ;a++)
using namespace std;
void insort(int ,int*);
int getans(int,int,int *,int *);
int getmax(int *,int);
int getmin(int *,int);
int main(void){
    int n, k;
    cin>>n>>k;
    int w[n];
    int getsum = 0;
    rep(i,0,n){
        cin>>w[i];
        getsum += w[i];
    }
    insort(n,w);
    
    
    
    int a[k];
    rep(i,0,k){
        a[i] = w[n - k + i];
    }
    /*
    rep(i,0,k)cout<<a[i]<<" ";
    cout<<endl;
    */
    
    
    int ans = getans(n,k,w,a);
    int sum = 0;
    rep(i,0,k)sum += a[i];
    cout<<"array w : ";
    rep(j,0,n)cout<<w[j]<<" ";
    cout<<endl;
    cout<<"array a : ";
    rep(j,0,k)cout<<a[j]<<" ";
    cout<<endl;
    cout<<" 配列　wの総和 "<<getsum<<endl;
    cout<<" 配列　aの総和 "<<sum<<endl;
    
    cout<<ans<<endl;
    return 0;

}


int getans(int n,int k,int *w,int *a){
    static int i = 0;
    static int minj = 0;   
    int max = n - k - i - 1;
    i++;
    if(max < 0) return getmax(a,k); 
    a[minj] = a[minj] + w[max];
    minj = getmin(a,k);
    int ans = getans(n,k,w,a);
    return ans;
}

// get max number or min number 
int getmax(int *a,int k){
    int maxj = 0;
    rep(i,1,k){
        if(a[maxj] < a[i])maxj = i;
    }
    return a[maxj];
}

int getmin(int *a,int k){
    int minj = 0;
    rep(i,1,k){
        if(a[minj] > a[i])minj = i;
    }
    return minj;
}


//sort algorithm
void insort(int n,int *w){
    rep(i,0,n - 1){
        int j = i;
        int min = w[j+1];
        while(w[j] > min && j >= 0){
            w[j+1] = w[j];
            j--;
        }
        w[j+1] = min;
    }
    return ;
}
