// 20190205 02:13 ~ 02:25 ~ 02:54
#include <iostream>
using namespace std;

int t;
int arr[12][12];
int ans;

void recur(int idx, int used, int score) {
    if(idx==12) {
        if(ans<score) ans = score;
        return;
    }
    for(int i=1; i<=11; i++) {
        if(arr[idx][i] && (used&(1<<i))^(1<<i)) {
            recur(idx+1, (used|(1<<i)), score+arr[idx][i]);
        }
    }
}

int main() {
    cin>>t;
    while(t--) {
        for(int i=1; i<=11; i++){
            for(int j=1; j<=11; j++){
                cin>>arr[i][j];
            }
        }
        ans = 0;
        recur(1, 0, 0);
        cout<<ans<<endl;
    }
}