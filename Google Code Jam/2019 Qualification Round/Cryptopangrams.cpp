// round : 20190406 08:00 ~ 20190407 11:00
// 20190406 09:33 ~ 10:25 +3, solved only visible.. :)
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

int T;
vector<int> pv;
int arr[10001];

int main() {
    for(int i=2; i<=100; i++) {
        for(int j=i*2; j<=10000; j+=i) {
            arr[j] = 1;
        }
    }
    rep(i, 2, 10001) {
        if(arr[i]) continue;
        pv.pb(i);
    }
    cin>>T;
    rep(t, 1, T+1){
        int n, l; cin>>n>>l;
        map<int, int> mp;
        vector<int> v;
        vector<P> ans;
        rep(i, 0, l) {
            int curr; cin>>curr;
            v.pb(curr);
            for(auto j : pv) {
                if(curr%j == 0) {
                    mp[j]++;
                    mp[curr/j]++;
                    ans.pb({j, curr/j});
                    break;
                }
            }
        }
        map<int, char> itocMp;
        int iter = 0;
        for(auto i : mp) {
            itocMp[i.xx] = (char)('A' + iter);
            iter++;
        }
        // print ans
        string ansS = "";
        int currLast; //1:xx, 2:yy
        // try ansS[0] = itocMp[ans[0].xx];
        ansS += itocMp[ans[0].xx];
        currLast = 1;
        int can = true;
        rep(i, 0, ans.size()-1) {
            if(currLast == 1) {
                if(ans[i].yy == ans[i+1].xx) {
                    ansS += itocMp[ans[i].yy];
                    currLast = 1;
                } else if (ans[i].yy == ans[i+1].yy) {
                    ansS += itocMp[ans[i].yy];
                    currLast = 2;
                } else {
                    can = false;
                    break;
                }
            } else {
                if(ans[i].xx == ans[i+1].xx) {
                    ansS += itocMp[ans[i].xx];
                    currLast = 1;
                } else if (ans[i].xx == ans[i+1].yy) {
                    ansS += itocMp[ans[i].xx];
                    currLast = 2;
                } else {
                    can = false;
                    break;
                }
            }
        }
        if(can && currLast == 1) {
            ansS += itocMp[ans[ans.size()-1].yy];
        } else if(can && currLast == 2) {
            ansS += itocMp[ans[ans.size()-1].xx];
        }
        // try ansS[1] = itocMp[ans[0].yy];
        else {
            ansS = "";
            ansS += itocMp[ans[0].yy];
            currLast = 2;
            rep(i, 0, ans.size()-1) {
                if(currLast == 1) {
                    if(ans[i].yy == ans[i+1].xx) {
                        ansS += itocMp[ans[i].yy];
                        currLast = 1;
                    } else if (ans[i].yy == ans[i+1].yy) {
                        ansS += itocMp[ans[i].yy];
                        currLast = 2;
                    } else {
                        can = false;
                        break;
                    }
                } else {
                    if(ans[i].xx == ans[i+1].xx) {
                        ansS += itocMp[ans[i].xx];
                        currLast = 1;
                    } else if (ans[i].xx == ans[i+1].yy) {
                        ansS += itocMp[ans[i].xx];
                        currLast = 2;
                    } else {
                        can = false;
                        break;
                    }
                }
            }
            if(currLast == 1) {
                ansS += itocMp[ans[ans.size()-1].yy];
            } else if(currLast == 2) {
                ansS += itocMp[ans[ans.size()-1].xx];
            }
        }
        cout<<"Case #"<<t<<": "<<ansS<<endl;
    }
    return 0;
}