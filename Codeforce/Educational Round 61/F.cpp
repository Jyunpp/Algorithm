// 20190306 01:23 ~ 02:03
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

int sz;
vector<char> v;
int dp[501][501][2];

int solve(int s, int e, int needToDelete) {
    if(s>e) return 0;
    if(e>=sz|| s>=sz) return 0;
    int ret = needToDelete;
    if(s==e) {
        // cout<<"s e ne "<<s<<", "<<e<<", "<<needToDelete<<" : "<<ret<<endl;
        dp[s][e][needToDelete] = ret;
        return ret;
    }
    // bool exist = false;
    int eIdx = 0;
    if(dp[s][e][needToDelete] != -1) return dp[s][e][needToDelete];
    int tempRet = solve(s+1, e, 1);
    rep(i, s+1, e+1) {
        if(v[i] == v[s]) {
            // exist = true;
            eIdx = i;
            tempRet = min(tempRet, solve(s+1, eIdx-1, 1) + solve(eIdx, e, 0));
        }
    }
    ret += tempRet;
    // if(!exist) ret += tempRet;
    // else {
        // ret += min(solve(s+1, e, 1), solve(s+1, eIdx-1, 1) + solve(eIdx, e, 0));
    // }
    dp[s][e][needToDelete] = ret;
    // cout<<"s e ne "<<s<<", "<<e<<", "<<needToDelete<<" : "<<ret<<endl;
    return ret;
}

int main() {
    rep(i, 0, 501) rep(j, 0, 501) rep(k, 0, 2) dp[i][j][k] = -1;
    int n;
    cin>>n;
    string s; cin>>s;
    v.push_back(s[0]);
    rep(i, 1, n) {
        if(s[i] == s[i-1]) continue;
        v.push_back(s[i]);
    }
    sz = v.size();
    int result = solve(0, sz-1, 1);
    cout<<result<<endl;
    return 0;
}