//20180221 15:25 ~ 15:35
//20180221 21:30 ~ 10:18
// misunderstand : after sorted arr Order by arr[i].xx , i thinked LIS(Longest Increase Subsequence)
#include <iostream>
#include <stdio.h>
#include <algorithm>

#define xx first
#define yy second
using namespace std;

typedef pair<int, int> P;

int T, N;
P arr[100001];
//int dp[100001];

int main(){
    cin>>T;
    while(T--){
        scanf("%d", &N);
        for(int i=0; i<=100000; i++) {arr[i].xx=111111;arr[i].yy=0;}//dp[i] = 0;}
        for(int i=1; i<=N; i++){
            scanf(" %d %d", &arr[i].xx, &arr[i].yy);
        }
        sort(arr, arr+N+1, [](P a, P b){return a.xx<b.xx;});
        
        int ret = 1;
        int curr = arr[0].yy;
        for(int i=1; i<N; i++){
            if(arr[i].yy<curr){
                curr = arr[i].yy;
                ret++;
            }
        }
        // misunderstaded problem
        // for (int i = 1; i <= N; ++i) {
        //     int curr = arr[N-i].yy;
        //     int *pos = lower_bound(dp + 1, dp + ret + 1, curr);
        //     *pos = curr;
        //     if (pos == dp + ret + 1){
        //         ret++;
        //         //cout<<"curr : "<<curr<<endl;
        //     }
        // }
        cout<<ret<<endl;
    }
    return 0;
}   