// 20190311 19:59 ~ 20:22 +2
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
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

int n, k, arr[5001];
int num[5001];
int ans[5001];
vector<int> v[5001];
int maxNum;
int maxCurr;

int main() {
    cin>>n>>k;
    rep(i, 1, n+1) {
        int curr; cin>>curr;
        arr[i] = curr;
        v[curr].push_back(i);
        num[curr]++;
        maxCurr = max(curr, maxCurr);
        maxNum = max(maxNum, num[curr]);
    }
    if(maxNum>k) {
        cout<<"NO";
        return 0;
    }
    cout<<"YES"<<endl;
    int iter = 1;
    rep(i, 1, maxCurr+1) {
        for(auto j : v[i]) {
            ans[j] = iter;
            iter++;
            if(iter>k) iter-=k;
        }
    }
    rep(i, 1, n+1){
        cout<<ans[i]<<" ";
    }
    return 0;
}