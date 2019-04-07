// round : 20190406 08:00 ~ 20190407 11:00
// 20190406 09:01 ~ 09:25
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

int n, T;
int sz = 1;

int main() {
    cin>>T;
    rep(t, 1, T+1){
        sz = 1;
        string s; cin>>s;
        string ret1 = "";
        string ret2 = "";
        rep(i, 0, s.size()) {
            int curr = (int)(s[i]-'0');
            int a = curr/2 + curr%2;
            int b = curr/2;
            while(a==4||b==4) {
                a++;
                b--;
            }
            ret1 += (char)('0' + a);
            ret2 += (char)('0' + b);
        }
        ret1 = (ret1[0] == '0' && ret1.size()!=1 ) ? ret1.substr(1) : ret1;
        ret2 = (ret2[0] == '0' && ret2.size()!=1 ) ? ret2.substr(1) : ret2;
        cout<<"Case #"<<t<<": "<<ret1<<" "<<ret2<<endl;
    }
    return 0;
}