// 20190308 00:30 ~ 00:56 -3
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

int n, ret;
vector<int> v;
int currTeamMax;
int currRet;

int main() {
    cin>>n;
    rep(i, 0, n){
        int temp; cin>>temp;
        v.pb(temp);
    }
    sort(v.begin(), v.end(), [](int a, int b){return a>b;});
    queue<int> q;
    q.push(v[0]);
    currRet = 1; ret = 1;
    rep(i, 1, n){
        if(v[i] >= q.front()-5) {
            currRet++;
            q.push(v[i]);
        }
        else {
            ret = max(ret, currRet);
            while(!q.empty() && v[i] < q.front()-5) {
                q.pop(); currRet--;
            }
            q.push(v[i]);
            currRet++;
        }
    }
    ret = max(ret, currRet);
    cout<<ret<<endl;
    return 0;
}