// 20190319 23:45 ~ 23:57
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
map<int, int> mp;

int main() {
    cin>>n;
    rep(i, 1, n) {
        cin>>arr[i];
    }
    int curr = 0;
    int mini = 0;
    int maxi = 0;
    mp[curr]++;
    int can = true;
    rep(i, 1, n) {
        curr+=arr[i];
        mp[curr]++;
        if(mp[curr]!=1) {
            can = false;
            break;
        }
        mini = min(mini, curr);
        maxi = max(maxi, curr);
    }
    if(!can || maxi-mini != n-1) {
        cout<<-1<<endl;
    } else {
        curr = -mini + 1;
        cout<<curr<<" ";
        rep(i, 1, n) {
            curr += arr[i];
            cout<<curr<<" ";
        }
    }
    return 0;
}