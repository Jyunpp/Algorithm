// 20190412 18:08 ~ 19:22 +6
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

int main() {
    cin>>T;
    rep(t, 1, T+1) {
        int ret = 0;
        int n, l;
        cin>>n>>l;
        vector<string> v;
        map<char, int> mp[10];
        rep(i, 0, n) {
            string s; cin>>s;
            v.pb(s);
        }
        set<string> se;
        rep(i, 0, n) {
            se.insert(v[i]);
        }
        v.clear();
        for(auto i : se) {
            v.pb(i);
        }
        rep(i, 0, v.size()) {
            string s = v[i];
            rep(j, 0, l) {
                mp[j][s[j]]++;
            }
        }
        int curr = 1;
        rep(i, 0, l) {
            curr *= mp[i].size();
        }
        int realN = v.size();
        cout<<"Case #"<<t<<": ";
        if(realN >= curr) {
            cout<<"-"<<endl;
        } else {
            string ret = "";
            map<string, int> mps;
            queue<string> q;
            for(auto i : mp[0]) {
                q.push(string(1, i.xx));
            }
            int iter = 0;
            while(q.size()<=realN) {
                int sz = q.size();
                iter++;
                while(sz--) {
                    string currS = q.front(); q.pop();
                    for(auto i : mp[iter]) {
                        q.push(currS + i.xx);
                    }
                }
            }
            //iter == 2 -> length == 3
            rep(i, 0, v.size()) {
                // already have
                mps[v[i].substr(0, iter+1)]+=50000;
            }
            while(!q.empty()) {
                string currS = q.front(); q.pop();
                mps[currS] ++;
            }
            for(auto i : mps) {
                if(i.yy < 50000){
                    ret = i.xx;
                    break;
                }
            }
            // iter == 2 -> lenth == 3 -> remain lenth == L-iter-1
            ret += v[0].substr(iter+1);
            cout<<ret<<endl;
        }
    }
    return 0;
}