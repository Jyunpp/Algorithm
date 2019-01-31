// 20190131 14:15 ~ 14:27 메모리 초과. 수정예정.
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
typedef pair<ll, ll> Pll;

int n;
ll arr[3][37];
ll ans;
vector<int> ansVector;

int main(){
    cin>>n;
    for(int i=1; i<=2; i++) {
        for(int j=1; j<=n; j++) {   
            cin>>arr[i][j];
        }
    }
    
    ans = 10e15 *36;

    queue<pair<vector<int>, pair<int, ll>>> q; // {tempAnsVector, {numOfTeam1, diff}}
    vector<int> initVector;
    P initP = {0, 0};
    q.push({initVector, initP});
    while(!q.empty()) {
        vector<int> currVector = q.front().xx;
        int numOfTeam1 = q.front().yy.xx;
        ll diff = q.front().yy.yy;
        q.pop();
        
        int currSize = currVector.size();
        if(currSize < n) {
            vector<int> nextT2Vector = currVector;
            nextT2Vector.push_back(2);
            q.push({nextT2Vector, {numOfTeam1, diff - arr[2][currSize+1]}});
            if(numOfTeam1 < n/2) {
                vector<int> nextT1Vector = currVector;
                nextT1Vector.push_back(1);
                q.push({nextT1Vector, {numOfTeam1 + 1, diff + arr[1][currSize+1]}});
            }
        }
        else {
            diff = diff < 0 ? diff*-1 : diff;
            if (diff < ans) {
                ans = diff;
                ansVector = currVector;
            }
        }
    }

    for(int i : ansVector) {
        cout<<i<<" ";
    }
    return 0;
}