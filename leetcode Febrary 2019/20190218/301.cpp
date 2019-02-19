// 20190218 22:45 ~ 
// 20190219 19:18 ~ 
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
#include <set>
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
    vector<string> removeInvalidParentheses(string s) {
        vector<string> ret;
        if(s.empty()) {
            ret.push_back("");
            return ret;
        }
        s +="(";
        set<string> visited;
        int finished = 0;
        queue<string> q;
        q.push(s);
        while(!q.empty()) {
            int sz = q.size();
            while(sz--){
                string curr = q.front(); q.pop();
                rep(i, 0, curr.size()) {
                    if(curr[i] != '(' && curr[i] != ')') continue;
                    string next = curr.substr(0, i) + curr.substr(i+1);
                    if(visited.find(next) != visited.end()) continue;
                    visited.insert(next);
                    int test = 0;
                    int validStr = 1;
                    rep(j, 0, next.size()) {
                        if(next[j] =='(') test ++;
                        else if(next[j] == ')') test --;
                        if(test<0) validStr = 0;
                    }
                    if(test) validStr = 0;
                    if(validStr) {
                        ret.push_back(next);
                        cout<<next<<endl;
                        finished = 1;
                    }
                    else {
                        q.push(next);
                    }
                }
            }
            if(finished) break;
        }
        if(ret.empty()) {
            ret.push_back("");
            return ret;
        }
        return ret;
    }
};

int main() {
    Solution solution;
    string s;
    cin>>s;
    solution.removeInvalidParentheses(s);
    return 0;
}