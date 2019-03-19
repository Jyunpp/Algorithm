// 20190319 
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

int n;
queue<int> arrL[26];
queue<int> qL;
queue<int> arrR[26];
queue<int> qR;

int main() {
    cin>>n;
    rep(i, 1, n+1) {
        char ch; cin>>ch;
        if(ch=='?') qL.push(i);
        else arrL[ch-'a'].push(i);
    }
    rep(i, 1, n+1) {
        char ch; cin>>ch;
        if(ch=='?') qR.push(i);
        else arrR[ch-'a'].push(i);
    }
    int ret = 0;
    rep(i, 0, 26) {
        ret += min(arrL[i].size(), arrR[i].size());
    }
    ret += (qL.size() + qR.size());
    if(ret>n) ret = n;
    cout<<ret<<endl;
    if(ret == 0) {
        return 0;
    }
    rep(i, 0, 26) {
        while(!arrL[i].empty() && !arrR[i].empty()) {
            cout<<arrL[i].front()<<" "<<arrR[i].front()<<endl;
            arrL[i].pop();
            arrR[i].pop();
        }
    }
    int iter = 0;
    while(!qL.empty()) {
        while(iter<=25 && arrR[iter].empty()) iter++;
        if(iter==26) {
            break;
        }
        cout<<qL.front()<<" "<<arrR[iter].front()<<endl;
        qL.pop();
        arrR[iter].pop();
    }
    iter = 0;
    while(!qR.empty()) {
        while(iter<=25 && arrL[iter].empty()) iter++;
        if(iter==26) {
            break;
        }
        cout<<arrL[iter].front()<<" "<<qR.front()<<endl;
        arrL[iter].pop();
        qR.pop();
    }
    while(!qL.empty() && !qR.empty()) {
        cout<<qL.front()<<" "<<qR.front()<<endl;
        qL.pop();
        qR.pop();
    }
    return 0;
}