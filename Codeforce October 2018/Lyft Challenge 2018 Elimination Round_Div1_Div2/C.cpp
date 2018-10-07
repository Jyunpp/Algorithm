// 20181008 02:56 ~  03:32
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <math.h>
using namespace std;

#define sd(x) scanf(" %d", &x);
#define pb push_back
#define xx first
#define yy second

typedef long long ll;
typedef pair<int, int> P;

int n;
int arr[100001];
int dp[100001];

int solve(int idx, int curr){
    int &ret = dp[idx];
    if(ret!=0){
        return ret;
    }
    int i=idx;
    while(i-curr>0) i-=curr;
    ret = -1;
    for(i; i<=n; i+=curr){
        if(arr[i]>curr){
            if((-1*solve(i,arr[i]))==1){
                ret = 1;
            }
        }
    }
    return ret;
}

int main() {
	cin>>n;
    for(int i=1; i<=n; i++){
        cin>>arr[i];
    }
    for(int i=1; i<=n; i++){
        if(solve(i, arr[i])==1){
            cout<<"A";
        }
        else{
            cout<<"B";
        }
    }
}