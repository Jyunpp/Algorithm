// 20190325 21:52 ~ 22:21
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

int n, m;
int arr[1001][1001];
P e[1001][1001];
P s[1001][1001];

int main() {
    cin>>n>>m;
    rep(i, 1, n+1) {
        rep(j, 1, m+1) {
            sd(arr[i][j]);
        }
    }
    rep(i, 1, n+1) {
        map<int, vector<int> > mp; // 숫자, idx
        rep(j, 1, m+1) {
            mp[arr[i][j]].push_back(j);
        }
        int sz = mp.size();
        int iter = 1;
        for(auto j : mp) {
            for(auto k : j.yy){
                e[i][k] = {sz, iter}; // 몇 개 중 몇 번째..
            }
            iter++;
        }
    }
    rep(i, 1, m+1) {
        map<int, vector<int> > mp; // 숫자, idx
        rep(j, 1, n+1) {
            mp[arr[j][i]].push_back(j);
        }
        int sz = mp.size();
        int iter = 1;
        for(auto j : mp) {
            for(auto k : j.yy){
                s[k][i] = {sz, iter}; // 몇 개 중 몇 번째..
            }
            iter++;
        }
    }
    rep(i, 1, n+1) {
        rep(j, 1, m+1) {
            int curr = max(e[i][j].xx, s[i][j].xx);
            curr = max(curr, e[i][j].yy + (s[i][j].xx-s[i][j].yy));
            curr = max(curr, s[i][j].yy + (e[i][j].xx-e[i][j].yy));
            cout<<curr<<" ";
        }
        cout<<endl;
    }
    return 0;
}