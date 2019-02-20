// 20190219 23:36 ~ 24:20
// 20190220 19:55 ~ 20:28
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
    int dp[1001][1001] = {0,}; // dp[x][y] : 1 if s.substr(i,j) is palindrome
    string longestPalindrome(string s) {
        if(s.empty()) return "";
        if(s.size()==1) return s;
        
        int retLen = 1;
        string ret = s.substr(0,1);
        rep(i, 0, s.size()) dp[i][i] = 1;
        // len of substr that will be checked 
        for(int i=2; i<=s.size(); i++) {
            // start index of substr
            for(int j=0; j+i-1<s.size(); j++) {
                int l = j;
                int r = j+i-1;
                dp[l][r] = (s[l] == s[r] && (l+1>r-1 || dp[l+1][r-1]));
                if(dp[l][r] && retLen < r-l+1) {
                    retLen = r-l+1;
                    ret = s.substr(l, r-l+1);
                }
            }
        }
        return ret;
    }
};

int main() {
    while(true){
    Solution sol;
    string s;
    cin>>s;
    cout<<sol.longestPalindrome(s)<<endl<<endl;
    }
    return 0;
}