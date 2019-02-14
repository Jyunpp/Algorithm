// 20190214 22:40 ~ 23:30
/*
* N <= 10^18 (= 1000^6 = 2^60)
*  => 절반씩 줄여나가면, 60번안에 가능.
*/
// 세번째 케이스 W/A인데 아마도 범위 문제인듯.
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

typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> Pll;

int t;
ll n, k;

void divide(queue<Pll> &q, ll curr, ll currCnt) {
    if(curr%2 == 0) {
        q.push({curr/2, currCnt});
        q.push({(curr/2) - 1, currCnt});
    } 
    else {
        q.push({curr/2, currCnt*2});
    }
}

int main() {
    cin>>t;
    rep(T, 1, t+1) {
        cin>>n>>k;
        ll currDivCnt = 0;
        ll div = 0;
        queue<Pll> q; // remain seat, count
        q.push({n, 1});
        while(true) {
            if( currDivCnt + pow(2, (div)) >= k ) break;
            currDivCnt += pow(2, (div));
            div++;
            vector<Pll> v;
            while(!q.empty()) {
                v.push_back(q.front());
                q.pop();
            }
            sortV(v, [](Pll a, Pll b){return a.xx > b.xx;});

            ll curr = v[0].xx;
            ll currCnt = v[0].yy;
            for(int i=1; i<v.size();) {
                if(curr == v[i].xx) currCnt += v[i].yy;
                else {
                    divide(q, curr, currCnt);
                    curr = v[i].xx;
                    currCnt = v[i].yy;
                }
                i++;
            }
            divide(q, curr, currCnt);
        }
        
        vector<Pll> v;
        while(!q.empty()) {
            v.push_back(q.front());
            q.pop();
        }
        sortV(v, [](Pll a, Pll b){return a.xx > b.xx;});
        int i=0;
        Pll resultStatus = v[i];
        while(currDivCnt < k) {
            currDivCnt += v[i].yy;
            resultStatus = v[i++];
        }
        Pll ret;
        if(resultStatus.xx%2) ret = {resultStatus.xx/2, (resultStatus.xx/2)};
        else ret = {resultStatus.xx/2, resultStatus.xx/2 - 1};
        cout<<"Case #"<<T<<": "<<ret.xx<<" "<<ret.yy<<endl;
    }
    return 0;
}