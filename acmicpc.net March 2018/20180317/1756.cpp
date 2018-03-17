//20180317 22:39 ~ 22:56 ~ 23:45
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

int D, N, arr[300001], temp;
vector<int> v;
int main(){
    cin>>D>>N;
    sd(arr[1]); temp = arr[1];
    v.resize(D); v[D-1] = temp;
    for(int i=2; i<=D; i++){ 
        sd(arr[i]);
        if(arr[i]<temp) temp = arr[i];
        v[D-i] = temp;
    }
    int ret = 0;
    for(int i=1; i<=N; i++) sd(arr[i]);
    for(int i=1; i<=N; i++){
        int currR = arr[i];
        auto lb = lower_bound(v.begin() + ret, v.end(), currR);
        int currIdx = lb - v.begin();
        ret = currIdx + 1;
        // cout<<"test : "<<ret<<endl;
        if(ret >D) break;
    }
    // think idx start 0  & need to calc
    cout<<D-(ret-1)<<endl; //temp
    return 0;
}