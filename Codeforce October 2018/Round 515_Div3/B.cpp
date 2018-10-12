// 20181012 23:35 ~ 20181013 00:05
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
#include <map>
using namespace std;

#define sd(x) scanf(" %d", &x);
#define pb push_back
#define xx first
#define yy second

typedef long long ll;
typedef pair<int, int> P;

int n, r;
int arr[4010];
int maxN;

int recur(int on, int idx,int currIdx, int num){
    if(on>num) return 0;
    if(on<=num && idx + r - 1 >=n) return 1;
    int ret = 0;
    for(int i=idx+2*r-1; i>=currIdx+1; i--){
        if(arr[i]){
            ret += recur(on+1, i, i, num);
            break;
            if(ret) return ret;
        }
    }
    return ret;
}
int can(int num){
    if(num==0)return 0;
    int ret = 0;
    for(int i=1, temp = min(r,n); i<=temp; i++){
        if(arr[i]){
            ret += recur(1, i,i, num);
            if(ret) return ret;
        }
    }
    return ret;
}
int main() {
    cin>>n>>r;
    for(int i=1; i<=n; i++){
        cin>>arr[i];
        maxN += arr[i];
    }
    int L = 1, R = maxN; 
    int ans = -1;
    while(L<=R){
        int mid = (L+R)/2;
        if(can(mid)){
            ans = mid;
            R = mid-1;
        } else{
            L = mid+1;
        }
    }
    cout<<ans<<endl;
    return 0;
}