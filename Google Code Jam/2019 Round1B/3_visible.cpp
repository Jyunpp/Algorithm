// 20190429 01:16 ~ 
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
#include <set>
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

int T;
ll ret;
int n, k;
int C[100001];
int D[100001];
int visited[100001];

void recur(int s, int e, int curr) {
    if(visited[curr]) return;
    // visited[curr]++;
    // cout<<"s, e, curr : "<<s<<", "<<e<<", "<<curr<<endl;
    if(s==e) {
        if(abs(C[curr]-D[curr]) <= k) ret++;
        return ;
    }
    int mid = curr;
    int lCurr = -987654321;
    int rCurr = -987654321;
    int lCurrIdx, rCurrIdx;
    rep(i, s, mid) {
        if(lCurr < C[i]) {
            lCurr = C[i];
            lCurrIdx = i;
        }
    }
    rep(i, mid+1, e+1) {
        if(rCurr < C[i]) {
            rCurr = C[i];
            rCurrIdx = i;
        }
    }
    vector<P> dv; // value, idx
    rep(i, s, e+1) {
        dv.pb({D[i], i});
    }
    sort(dv.begin(), dv.end(), [](P a, P b){return a.xx> b.xx;});
    int dSIdx, dEIdx;
    int iter = 0;
    while(iter != dv.size() && abs(dv[iter].xx - C[curr]) > k) iter++;
    dSIdx = iter;
    if(dSIdx != dv.size()) {
        vector<int> v;
        while(iter != dv.size() && abs(dv[iter].xx - C[curr]) <= k) {
            v.pb(dv[iter].yy);
            iter++;
        }
        sort(v.begin(), v.end()); // possible idx (increasing order)
        // rep(i, v[0], v[v.size()-1]+1) {
        //     if(i>=)
        // }
        // auto upb = upper_bound(v.begin(), v.end(), curr);
        // int upbIdx = upb - v.begin();
        // auto low = lower_bound(v.begin(), v.end(), curr);
        // int lowIdx = low - v.begin();
        // (v[v.size()-1]-upbIdx) * 
        // cout<<"upbIdx = "<<upbIdx<<endl;
        if(v[0] <= curr && curr <= v[v.size()-1]){
            int ll, rr;
            ll=rr=1;
            rep(i, 0, v.size()-1) {
                ll += v[i]<curr;
                rr += v[i]>curr;
            }
            ret += ll*rr;
            visited[curr]++;
        }
        // int ll, rr;
        // int iter = 0;
        // while(iter!=v.size() && v[iter] < curr) iter++;

        // if(v[0] <= curr && curr <= v[v.size()-1]){
        //     // ret += v.size();
        //     ret += (v[v.size()-1] - curr);
        //     // ret ++;
        //     ret += (curr - v[0]);
        else if (v[0]>= curr) {
            bool can = true;
            rep(i, curr, v[0]+1) {
                if(D[i] > D[v[0]]) {
                    can = false;
                    break;
                }
            }
            if(can) {
                ret += v.size();
                visited[curr]++;
            }
        } else if ( v[v.size()-1] <= curr) {
            bool can = true;
            rep(i, v[v.size()-1] +1, curr+1) {
                if(D[i] > D[v[v.size()-1]]) {
                    can = false;
                    break;
                }
            }
            if(can) {
                ret += v.size();
                visited[curr]++;
            }
        }
        // cout<<ret<<endl;
        // rep(i, 0, v.size()) {
        //     cout<<i+1<<" ";
        // }
        // cout<<endl;
        // int temp1 = (e - (s-1));
        // temp1*=(temp1+1);
        // temp1/=2;
        // int temp2 = (v[0] - (s-1));
        // temp2*=(temp2+1);
        // temp2/=2;
        // int temp3 = (v[v.size()-1] - (e-1));
        // temp3*=(temp3+1);
        // temp3/=2;
        // cout<<temp1<<", "<<temp2<<", "<<temp3<<endl;
        // temp1 -=(temp2+temp3);
        // cout<<temp1<<endl;
        // if(temp1>=0) {
        //     ret += temp1;
        // }
        // visited[curr]++;
    }
    if(mid-1 != curr && s <= mid-1 && lCurr != -987654321) recur(s, mid-1, lCurrIdx);
    if(s != mid+1 && mid + 1 <= e && rCurr != -987654321) recur(mid+1, e, rCurrIdx);
}

int main() {
    cin>>T;
    rep(t, 1, T+1) {
        cin>>n>>k;
        rep(i, 1, n+1) cin>>C[i];
        rep(i, 1, n+1) cin>>D[i];
        rep(i, 1, n+1) visited[i] = 0;
        ret = 0;
        // int maxIdx;
        int maxNum = -987654321;
        rep(i, 1, n+1) {
            if(C[i]>maxNum) {
                maxNum = C[i];
                // maxIdx = i;
            }
        }
        rep(i, 1, n+1) {
            if(C[i] == maxNum) {
                recur(1, n, i);
            }
        }
        // recur(1, n, maxIdx);
        cout<<"Case #"<<t<<": ";
        cout<<ret<<endl;
    }
    return 0;
}