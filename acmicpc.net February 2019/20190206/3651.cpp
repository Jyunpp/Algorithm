// 20190206 13:00 ~ 
/*
* 2 <= m <= 10^15 = 1000^5 ≈ 2^50
*  => 이분탐색 시 50번 이내로 접근가능
* nCr 가 m인지 계산하여 저장. r=1일 때, r=2일 때, r=3일 때, ... 순으로
*  각 r에 대해서 앞선 계산을 제외하고 의미있는 min(nCr)은, n==r*2일 때, => r*2Cr > m 이면 그만.
*  각 r에 대해서 n을 이분탐색으로 찾음. (r*2, 적절한 high) 범위. (적절한 high : m)
* long long 범위 넘어서는 것 방지하기 위해, (x*y < z <=> x < z/y)..........
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define xx first
#define yy second

typedef long long ll;
typedef pair<long long, long long> Pll;

ll m;
vector<Pll> res;

ll comb(ll n, ll k) {
    ll ret = 1;
    for(ll i=0; i<k; i++) {
        // ll 범위 넘는 것 막기위해 곱하기 전 확인, (x*y < z <=> x < z/y)
        if(ret > (1+m/(n-i))*(i+1)) return m+1; // 결과가 ret > m 여부만 확인하면 됨.
        ret *= (n-i);
        ret /= (1+i);
    }
    return ret;
}

int main() {
    cin>>m;

    for(ll k=0; comb(2*k, k)<=m; k++) {
        ll lo = 2*k, hi = m;
        while (lo<hi) {
            ll mid = (lo+hi)>>1;
            if(comb(mid, k) < m) lo = mid+1; else hi = mid;
        }
        if(comb(hi, k) == m) {
            res.push_back({hi, k});
            if(hi != 2*k) res.push_back({hi, hi-k});
        }
    }
    sort(res.begin(), res.end());
    
    cout<<res.size()<<endl;
    for(Pll curr : res) {
        cout<<curr.xx<<" "<<curr.yy<<endl;
    }

    return 0;
}