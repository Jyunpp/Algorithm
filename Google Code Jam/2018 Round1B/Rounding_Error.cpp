// 20190404 19:20 ~ 20:02 +3, solved visible1, visible2
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

int T, N, L;

int main() {
    cin>>T;
    rep(t, 1, T+1) {
        int ret = 0;
        cin>>N>>L;
        int need = N;
        vector<P> v;
        rep(i, 1, L+1) {
            int a; cin>>a;
            need -= a;
            v.pb({a, ((a*1000)/N)%10});
        }
        // cout<<"initial need : "<<need<<endl;
        sort(v.begin(), v.end(), [](P a, P b){return a.yy>b.yy;});
        int iter = 0;
        while(iter<L && ((v[iter].xx*1000)/N)%10>=5) iter++;
        while(iter<L && need) {
            P curr = v[iter];
            need--;
            v[iter].xx++;
            // cout<<"curr..."<<((curr.xx+1)*1000/N)<<endl;
            iter += ((((curr.xx+1)*1000/N)%10) >=5);
        }
        if(need) {
            // cout<<"need : "<<need<<endl;
            int mini = 0;
            while(((mini*1000)/N)%10<5) mini++;
            rep(i, 0, (need/mini)){
                v.pb({mini, 0});
            }
            v.pb({(need - (need/mini)*mini), 0});
        }
        // cout<<v.size()<<"+"<<endl;
        for(auto i : v){
            ret += (i.xx*100)/N + (((i.xx*1000)/N)%10>=5);
        }
        cout<<"Case #"<<t<<": "<<ret<<endl;
    }
}