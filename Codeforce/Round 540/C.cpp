// 20190303 17:15 ~ 18:52
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

int n;
int arr[1001];
int ret[21][21];

int main() {
    cin>>n;
    rep(i, 1, n*n+1) {
        int a; cin>>a;
        arr[a]++;
    }
    vector<int> v;
    rep(i, 1, 1001) {
        if(arr[i]) v.pb(arr[i]);
    }
    sort(v.begin(), v.end());
    
    bool yes = true;
    if(n%2==0){
        rep(i, 0, v.size()) {
            if(v[i]%4 != 0) yes = false;
        }
    } else {
        int one = 0;
        int two = 0;
        rep(i, 0, v.size()) {
            if(v[i]%4 != 0) {
                if(v[i]%4 == 1) one++;
                else if(v[i]%4 == 2) two++;
                else if(v[i]%4 == 3) {one++; two++;}
                else yes = false;
            }
        }
        if(one!=1) yes = false;
        if(two>n-1) yes = false;
        if( !( (two == n-1) || ( (n-1-two)>=0 && (((n-1)/2)*4-(two*2)) >=0 && (((n-1)/2)*4-(two*2))%4==0 ) ) ) yes = false;
    }
    if(!yes) {
        cout<<"NO"<<endl;
        return 0;
    } else {
        cout<<"YES"<<endl;
    }
    queue<P> ones;
    queue<P> twos;
    queue<P> fours;
    rep(i, 1, (n/2)+1) {
        rep(j, 1, (n/2)+1) {
            fours.push({i, j});
            fours.push({i, n+1-j});
            fours.push({n+1-i, j});
            fours.push({n+1-i, n+1-j});
        }
    }
    if(n%2 == 1) {
        ones.push({1 + n/2, 1 + n/2});
        rep(i, 1, 1 + n/2){
            twos.push({i, 1+n/2});
            twos.push({n+1-i, 1+n/2});
            twos.push({1+n/2, i});
            twos.push({1+n/2, n+1-i});
        }
    }
    rep(i, 1, 1001) {
        if(arr[i]%4 == 1 || arr[i]%4 == 3) {
            int y = ones.front().xx;
            int x = ones.front().yy;
            ones.pop();
            ret[y][x] = i;
            arr[i]--;
            i--;
        } else if (arr[i]%4 == 2) {
            rep(j, 1, 3){
                int y = twos.front().xx;
                int x = twos.front().yy;
                twos.pop();
                ret[y][x] = i;
            }
            arr[i]-=2;
            i--;
        } else if (arr[i] != 0 && arr[i]%4 == 0){
            if (!fours.empty()){
                rep(j, 1, 5){
                    int y = fours.front().xx;
                    int x = fours.front().yy;
                    fours.pop();
                    ret[y][x] = i;
                }
            } else {
                rep(j, 1, 5){
                    int y = twos.front().xx;
                    int x = twos.front().yy;
                    twos.pop();
                    ret[y][x] = i;
                }
            }
            arr[i]-=4;
            i--;
        }
    }
    rep(i, 1, n+1) {
        rep(j, 1, n+1) {
            cout<<ret[i][j]<<" ";
        }
        cout<<endl;
    }
}