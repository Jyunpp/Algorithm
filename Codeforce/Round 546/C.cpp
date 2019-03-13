// 20190312 22:18 ~ 22:46
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

int n, m;
int arr[3][1001][1001];

int main() {
    cin>>n>>m;
    rep(k, 1, 3) {
        rep(i, 1, n+1) {
            rep(j, 1, m+1) {
                cin>>arr[k][i][j];
            }
        }
    }
    int yes = true;
    rep(i, 1, n+m+1) {
        vector<int> v[2];
        rep(j, 1, i+1) {
            v[0].pb(arr[1][i+1-j][j]);
            v[1].pb(arr[2][i+1-j][j]);
        }
        sort(v[0].begin(), v[0].end());
        sort(v[1].begin(), v[1].end());
        rep(j, 0, v[0].size()){
            if(v[0][j] !=v[1][j]){
                yes = false;
                break;
            }
        }
        if(!yes) break;
    }
    if(yes) cout<<"YES";
    else cout<<"NO";
    return 0;
}