// 20190318 21:25 ~ 22:00
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

int n;
int arr[200001];
ll esum[200001];
map<ll, vector<int>> mp;

int main() {
    cin>>n;
    ll s = 0;
    rep(i, 1, n+1) {
        cin>>arr[i];
        s+=arr[i];
    }
    rep(i, 1, n+1) {
        esum[i] = s - arr[i]*2;
    }
    vector<ll> ev;
    rep(i, 1, n+1) {
        ev.push_back(esum[i]);
        mp[esum[i]].push_back(i);
    }
    sort(ev.begin(), ev.end());
    vector<int> ret;
    rep(i, 1, n+1) {
        auto lb = lower_bound(ev.begin(), ev.end(), arr[i]);
        if(arr[i]==*lb){
            if(mp[arr[i]].size()==1 && mp[arr[i]][0] == i){
                continue;
            }
            ret.push_back(i);
        }
    }
    cout<<ret.size()<<endl;
    for(auto i : ret) {
        cout<<i<<" ";
    }
    return 0;
}