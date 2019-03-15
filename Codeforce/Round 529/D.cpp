// 20190315 07:53 ~ 08:40
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

int n;
vector<int> near[200001];
int visited[200001];
int arr[2][200001];

int main() {
    cin>>n;
    rep(i, 1, n+1) {
        int a, b;
        cin>>a>>b;
        near[a].pb(b);
        near[b].pb(a);
        arr[0][i] = a;
        arr[1][i] = b;
    }

    vector<int> ret ;
    int curr = near[1][0];
    ret.pb(1);
    visited[1]++;
    while(true) {
        int end = true;
        rep(i, 0, 2){
            if(!visited[near[curr][i]]) {
                ret.pb(curr);
                visited[curr]++;
                curr = near[curr][i];
                end = false;
            }
        }
        if(end) {
            ret.pb(curr);
            break;
        }
    }
    int inverse = 0;
    if(
    !(((arr[0][1] == ret[1] && arr[1][1] == ret[2]) ||
        (arr[0][1] == ret[2] && arr[1][1] == ret[1])) ||
        ((arr[0][ret[n-1]] == ret[0] && arr[1][ret[n-1]] == ret[1]) ||
        (arr[0][ret[n-1]] == ret[1] && arr[1][ret[n-1]] == ret[0])))) 
        {inverse = 1;}
    if(inverse) {
        for(int i=n-1; i>=0; i--) {
            cout<<ret[i]<<" ";
        }
    }
    else {
        rep(i, 0, n){
            cout<<ret[i]<<" ";
        }
    }
    return 0;
}