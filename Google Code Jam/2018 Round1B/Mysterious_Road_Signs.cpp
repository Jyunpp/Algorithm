// 20190404 20:10 ~ 21:22 solved visible
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

int s;

int main() {
    int T; cin>>T;
    rep(t, 1, T+1) {
        cin>>s;
        vector<pair<int, P>> v;
        map<int, int> Mmp;
        map<int, int> Nmp;
        rep(i, 1, s+1){
            int d, a, b;cin>>d>>a>>b;
            v.pb({d, {a,b}});
            Mmp[d+a]++;
            Nmp[d-b]++;
        }
        P ret = {0, 0};
        map<P, int> mp;
        for(auto mm : Mmp){
            for(auto nn : Nmp){
                int M = mm.xx;
                int N = nn.xx;
                int start = 0;
                rep(i, 0, s) {
                    if(v[i].xx + v[i].yy.xx != M && v[i].xx - v[i].yy.yy != N) {
                        mp[{start, i-1}]++;
                        start = i+1;
                    }
                }
                if(start != s) mp[{start, s-1}]++;
            }
        }
        map<int, int> lenCnt;
        for(auto i : mp) {
            int currLen = (i.xx.yy - i.xx.xx + 1);
            lenCnt[currLen]++;
        }
        for(auto i : lenCnt){
            if(ret.xx < i.xx || (ret.xx == i.xx && ret.yy < i.yy)){
                ret = {i.xx, i.yy};
            }
        }
        cout<<"Case #"<<t<<": "<<ret.xx<<" "<<ret.yy<<endl;
    }
}