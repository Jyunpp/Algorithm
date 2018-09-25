// 20180925 12:38 ~ 13:41
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

int n, negative;
vector<int> zeroIdxs;
int maxNegative, maxNegativeIdx;
int arr[200001];
int oper;

void firstOper(int idx, int idx2){
    if(oper==n-1) return;
    if(idx>idx2){
        int temp = idx;
        idx = idx2;
        idx2 = temp;
    }
    cout<<1<<" "<<idx<<" "<<idx2<<endl;
    arr[idx] = 1;
    oper++;
}

void secondOper(int idx){
    if(oper==n-1) return;
    cout<<2<<" "<<idx<<endl;
    arr[idx] = 1;
    oper++;
}

void secondOper2(int idx, int idx2){
    int realIdx = max(idx, idx2);
    secondOper(realIdx);
}

int main(){
    cin>>n;
    maxNegative = -1987654321;
    for(int i=1, a; i<=n; i++){
        cin>>a;
        if(a==0){
            zeroIdxs.pb(i);
        }
        if (a<0){
            if(a>maxNegative){
                maxNegative = a;
                maxNegativeIdx = i;
            }
            negative++;
        }
    }

    int zeroSz = zeroIdxs.size();
    if(negative%2==0){
        if(zeroSz>1){
            for(int i=0; i<zeroSz-1; i++){
                firstOper(zeroIdxs[i], zeroIdxs[i+1]);
            }
        }
        if(zeroSz !=0){
            secondOper(zeroIdxs[zeroSz-1]);
        }
    }
    else {
        if(zeroSz>1){
            for(int i=0; i<zeroSz-1; i++){
                firstOper(zeroIdxs[i], zeroIdxs[i+1]);
            }
        }
        if(zeroSz !=0){
            firstOper(zeroIdxs[zeroSz-1], maxNegativeIdx);
            secondOper2(maxNegativeIdx, zeroIdxs[zeroSz-1]);
        }
        if(zeroSz==0){
            secondOper(maxNegativeIdx);
        }
    }

    vector<int> operIdx;
    for(int i=1; i<=n; i++){
        if(!arr[i]) operIdx.pb(i);
    }
    int sz = operIdx.size();
    for(int i=0; i<sz-1; i++){
        int curr = operIdx[i];
        int next = operIdx[i+1];
        firstOper(curr, next);
    }
}