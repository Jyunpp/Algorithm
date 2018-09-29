// 20180929 23:21 ~ 00:47
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

typedef long long ll;
typedef pair<int, int> P;

int n, m, d;
vector<P> t;    // time, idx
queue<P> q;     // time, ans
vector<int> ans;
int Ans = 1;

int main(){
    cin>>n>>m>>d;
    t = vector<P>(n);
    ans = vector<int>(n);
    for(int i=0; i<n; i++){
        cin>>t[i].xx;
        t[i].yy = i;
    }
    sort(t.begin(), t.end(), [](P a, P b){return a.xx<b.xx;});
    for(int i=0; i<n; i++){
        int curr = t[i].xx;
        int currIdx = t[i].yy;
        int prev = q.empty()?-1000000001:q.front().xx;
        int prevAns = q.empty()?1:q.front().yy;
        if(curr-prev >= d+1){
            ans[currIdx] = prevAns;
            if(!q.empty()) q.pop();
            q.push({curr, ans[currIdx]});
        }
        else {
            if(q.size()==Ans)
                ans[currIdx] = ++Ans;
            else
                ans[currIdx] = (q.front().yy + q.size())%Ans;
            q.push({curr, ans[currIdx]});
        }
    }
    cout<<Ans<<endl;
    for(int i=0; i<n-1; i++){
        cout<<ans[i]<<" ";
    } cout<<ans[n-1];
    return 0;
}