// 20190315 07:27 ~ 07:52 ;; cout<<pow(2,6)쯤 하니까 이상하게 나와서,, (int)pow(2,6) 해야함 ;;
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
#define slld(x) scanf(" %lld", &x);
#define pb push_back
#define xx first
#define yy second
#define rep(i, l, r) for(int i=l; i<r; i++)
#define sortV(v, lambda) sort(v.begin(), v.end(), lambda)
#define powll(a, b) (ll) pow(a, b)

typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> Pll;

int n, k;
int pow2[31]; // use 0~30, 2^30 = 107,xxx,xxx
int ret[31];

int main() {
    cin>>n>>k;
    pow2[0] = 1;
    rep(i, 1, 31) pow2[i] = pow2[i-1]*2;
    int tempN = n;
    int cnt = 0;
    for(int i=30; i>=0; i--) {
        if(tempN>=pow2[i]) {
            ret[i] = 1;
            tempN-=pow2[i];
            cnt++;
        }
    }
    if(tempN!=0 || cnt > k) {
        cout<<"NO"<<endl;
        return 0;
    }
    if(cnt!=k) {
        int idx = 30;
        while(ret[idx]==0) idx--;
        while(cnt!=k) {
            if(idx==0){
                break;
            }
            ret[idx]--;
            ret[idx-1]+=2;
            if(ret[idx]==0) idx--;
            cnt++;
        }
    }
    if(cnt!=k){
        cout<<"NO"<<endl;
        return 0;
    }
    
    cout<<"YES"<<endl;
    rep(i, 0, 31) {
        rep(j, 0, ret[i]) {
            cout<<(int)pow(2, i)<<" ";
        }
    }
    return 0;
}