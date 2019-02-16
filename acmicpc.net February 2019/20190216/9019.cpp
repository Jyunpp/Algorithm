// 20190216 20:21 ~ 20:34
// 20190217 00:22 ~ 00:25
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

int t, s, e;
int visited[10001];

int D(int x) {
    return (x*2)%10000;
}
int S(int x) {
    if(x==0) return 9999;
    return x-1;
}
int L(int x) {
    return (x*10)%10000 + x/1000 ;
}
int R(int x) {
    return (x%10)*1000 + x/10;
}
int main() {
    int t;
    cin>>t;
    while(t--) {
        rep(i, 0, 10001) visited[i] = 0;
        cin>>s>>e;
        queue<pair<int, string>> q;
        q.push({s, ""});
        string ret;
        while(!q.empty()){
            int prev = q.front().xx;
            string prevS = q.front().yy;
            q.pop();
            if(prev==e) {
                ret = prevS;
                break;
            }
            if(!visited[D(prev)]){
                q.push({D(prev), prevS+"D"});
                visited[D(prev)] = 1;
            }
            if(!visited[S(prev)]){
                q.push({S(prev), prevS+"S"});
                visited[S(prev)] = 1;
            }
            if(!visited[L(prev)]){
                q.push({L(prev), prevS+"L"});
                visited[L(prev)] = 1;
            }
            if(!visited[R(prev)]){
                q.push({R(prev), prevS+"R"});
                visited[R(prev)] = 1;
            }
        }
        cout<<ret<<endl;
    }
}