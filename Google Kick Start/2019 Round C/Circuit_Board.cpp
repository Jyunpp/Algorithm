// 20190526 18:14 ~ 18:47
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

int t;
int r, c, k;
int arr[301][301];
int rightBondary[301][301];

int main() {
    cin>>t;
    rep(T, 1, t+1) {
        int ret = 0;
        // input
        cin>>r>>c>>k;
        rep(i, 1, r+1) rep(j, 1, c+1) cin>>arr[i][j];

        // rightBondary 전처리
        rep(i, 1, r+1) {
            rep(j, 1, c+1) {
                int rbIdx = j;
                while(rbIdx+1 <=c && abs(arr[i][rbIdx+1] - arr[i][rbIdx]) <= k) rbIdx++;
                rightBondary[i][j] = (rbIdx-j); // 가능한 distance 저장
            }
        }

        // 3중 포문
        rep(i, 1, r+1) {
            rep(j, 1, c+1) {
                int currRb = -1;
                for(int k=0; i+k <=r; k++) {
                    // 인접한 row 간에 조건 확인
                    if(k!=0 && abs(arr[i+k-1][j] - arr[i+k][j]) > k) continue;

                    if(currRb == -1) currRb = rightBondary[i][j];
                    else currRb = min(currRb, rightBondary[i+k][j]); // righyBoundary 중 최소값이 가능한 값
                    
                    // 최대값 갱신
                    int columnLength = currRb+1;
                    int rowLength = k+1;
                    ret = max(ret, columnLength * rowLength);
                }
            }
        }
        
        cout<<"Case #"<<T<<": "<<ret<<endl;
    }
    return 0;
}