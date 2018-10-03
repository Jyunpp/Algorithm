// i < j 이면서 partialSum[j] - partialSum[i-1] < t 인 i, j 쌍의 개수
// => for j in [1, n] 에 대해서 생각 => j 고정 시 위 만족하는 i 개수
// 위는 j 고정 시 편의를 위해 partialSum[j] - t < partialSum[i-1] 로 쓸 수 있음
// i < j 는 각 loop(j에 대한) 마지막에 이번 j 를 고려대상에 넣어줌으로써 해결
// 매 j 당 고려대상 중 위를 만족하는 i 의 개수를 구하면..
// 고려대상? 만족하는 i의 개수를 구할 때 시간복잡도를 줄일만한..
// => fenwick tree => 업데이트 용이, 합 구하기 용이. 
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
#define lowbit(x) x&(-x);
// #define lbIdx(s,e,n) lower_bound()

typedef long long ll;
typedef pair<int, int> P;

const int N = 2e5 + 1;
int n;
ll t, ans;
ll tree[N];

void add(int idx, int n){
    while(idx<=N){
        tree[idx] += n;
        idx += lowbit(idx);
    }
}

ll sml(int idx){
    ll ret = 0;
    while(idx>0){
        ret += tree[idx];
        idx -= lowbit(idx);
    }
    return ret;
}

int main(){
    cin>>n>>t;
    vector<ll> ps(n+1, 0); // partial sum
    vector<ll> psAsc(n+1, 0); // partial sum, sorted
    for(int i=1; i<=n; i++){
        ll input;
        slld(input);
        ps[i] = ps[i-1] + input;
        psAsc[i] = ps[i];
    }
    sort(psAsc.begin() + 1, psAsc.end());
    // 위 주석과 다르게 j 글자만 i 로 사용하여 loop
    for(int i=1; i<=n; i++){
        if(ps[i]<t) ans++;
        //작은 것들 개수
        int y = lower_bound(psAsc.begin()+1, psAsc.end(), ps[i]-t+1) - psAsc.begin() - 1;
        //작은 것 중 j 이전 것(트리에 반영된 것) 구해서 전체 j-1 에서 뺌 => 큰 것의 개수
        ans += i-1-sml(y);
        //이번 (j) 의 위치 구해서 넣음. (다음 loop 에서 고려하기 위해)
        int x = lower_bound(psAsc.begin()+1, psAsc.end(), ps[i]) - psAsc.begin();
        add(x,1);
    }
    cout<<ans<<endl;
    return 0;
}