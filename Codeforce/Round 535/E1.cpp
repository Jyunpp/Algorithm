// 20190306 21:37 ~ 10:07
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
int arr[501];
vector<P> v;
vector<int> retV;

int main() {
    cin>>n>>m;
    rep(i, 1, n+1) cin>>arr[i];
    rep(i, 1, m+1) {
        int a, b; cin>>a>>b;
        v.push_back({a, b});
    }
    int ret = -987654321;
    rep(i, 1, n+1) {
        rep(j, 1, n+1) {
            if(i==j) continue;
            int tempRet = arr[i] - arr[j];
            vector<int> tempRetV;
            int cnt = 0;
            rep(k, 0, m) {
                int l = v[k].xx;
                int r = v[k].yy;
                if((l<=j && j<=r) && !(l<=i && i <=r)) {
                    tempRet++;
                    cnt++;
                    tempRetV.push_back(k+1);
                }
            }
            if(tempRet>ret) {
                ret = tempRet;
                retV = tempRetV;
            }
            tempRetV.clear();
        }
    }
    if(ret != -987654321) {
        cout<<ret<<endl;
        cout<<retV.size()<<endl;
        rep(i, 0, retV.size()) {
            cout<<retV[i];
            if(i!=retV.size()-1) cout<<" ";
        }
    } else {
        if(n==1){
            cout<<0<<endl<<0;
        }
        else {
            int tempRet2 = -987654321;
            rep(i, 1, n+1){
                rep(j, 1, n+1) {
                    if(i==j) continue;
                    tempRet2 = max(tempRet2, arr[i]-arr[j]);
                }
            }
            cout<<tempRet2<<endl;
            cout<<0;
        }
    }
    return 0;
}