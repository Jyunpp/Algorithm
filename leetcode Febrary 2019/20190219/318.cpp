// 20190219 01:35 ~ 01:50
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

class Solution {
public:
    int maxProduct(vector<string>& words) {
        int sz = words.size();
        vector<P> v;
        rep(i, 0, sz) {
            int curr = 0;
            for(char ch : words[i]){
                curr |=(1<<(ch-'a'));
            }
            v.push_back({curr, words[i].size()});
        }
        int ans = 0;
        rep(i, 0, sz){
            rep(j, 0, sz){
                if(i==j)continue;
                if(v[i].xx & v[j].xx) continue;
                ans = max(ans, v[i].yy*v[j].yy);
            }
        }
        return ans;
    }
};