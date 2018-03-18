// 20180318 15:23 ~ 17:39 ~ 18:24 ~ 18:44
// failed this problem .. but I don't know reason and can't get Sample I/O :(
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

ll calc(vector<ll> &tree, int node, int Lx, int s, int e){
    // cout<<"calc node, Lx, s, e : "<<node<<", "<< Lx<<", "<<s<<", "<<e<<" !!"<<endl;
    // cout<<"TREE SIZE : "<<tree.size()<<endl;
    if( s > Lx || e < Lx) return 0;
    if( s == Lx && Lx == e) return tree[node];
    return tree[node] + calc(tree, node*2, Lx, s, (s+e)/2) + calc(tree, node*2+1, Lx, (s+e)/2 + 1, e);
}

ll findResult(vector<vector<ll>> &treeArr, int Lx, int Ly, int treeSize){
    ll ret = 0;
    for(int i=0; i<Ly; i++){
        for(int j=0; j<Lx; j++){
            ret = max(ret, calc(treeArr[i], 1, j, 0, Lx-1));
            // cout<<"TEST RET : "<<ret<<endl;
            // test..
            // cout<<calc(treeArr[i], 1, j, 0, Lx)<<" ";
        }
        //test
        // cout<<endl;
    }
    return ret;
}

void fillArr(vector<vector<ll>> &treeArr, vector<int> idxs, int py, int ly, int lz){
    for(int i=py; i<py+ly; i++){
        for(auto &j : idxs){
            treeArr[i][j] += lz;
        }
    }
}
void calcVectorIndex(vector<vector<ll>> &treeArr, vector<int> &idxs, int node, int start, int end, int left, int right){
    if( left > end || right < start) return;
    if( left <= start && end <= right){
        idxs.pb(node);
        return;
    }
    calcVectorIndex(treeArr, idxs, node*2, start, (start+end)/2, left, right);
    calcVectorIndex(treeArr, idxs, node*2+1, (start+end)/2 + 1, end, left, right);
}

int main(){
    int Lx, Ly, N, lx, ly, lz, px, py;
    ll h, treeSize;
    cin>>Lx>>Ly>>N;
    // treeArr
    vector<vector<ll>> treeArr(Ly);
    // fill treeArr with tree
    h = (int)ceil(log2(Lx));
    treeSize = (1<<(h+1));
    for(int i=0; i<Ly; i++)
        treeArr[i] = vector<ll>(treeSize);
    
    // cout<<"Test treeSize : "<<treeSize<<endl;

    // input & calc
    for(int i=1; i<=N; i++){
        sd(lx);sd(ly);sd(lz);sd(px);sd(py);
        // calc vectorIdxs 
        vector<int> idxs;
        calcVectorIndex(treeArr, idxs, 1, 0, Lx-1, px, px+lx-1);    //-1 !!!!!!!!!!!!!!!!!!!!!!!!!
        
        // fill each tree while loop
        fillArr(treeArr, idxs, py, ly, lz);

        // cout<<"Test Idxs : ";
        // for(auto a : idxs) cout<<a<<" ";
        // cout<<endl;
        
        // cout<<"treeidx: ";
        // for(int j=0; j<treeSize; j++) cout<<j%10<<" ";
        // cout<<endl;
        // for(int k=0; k<Ly; k++){
        //     cout<<"k = "<<k<<"  : ";
        //     for(int j=0; j<treeSize; j++){
        //         cout<<treeArr[k][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        // cout<<"-------------------"<<endl;
        // test
        // cout<<"Current Status"<<endl;
        // for(int j=0; j<Ly; j++){
        //     for(int k=0; k<Lx; k++){
        //         int tempCurr = calc(treeArr[j], 1, k, 0, Lx-1);
        //         if((tempCurr/10)) cout<<tempCurr/10;
        //         // else if (!tempCurr) cout<<" ";
        //         else cout<<" ";
        //         cout<<tempCurr%10<<" ";
        //     }
        //     cout<<endl;
        // }
        // cout<<"---------------------------"<<endl;
        // cout<<"TEST ret : "<<findResult(treeArr, Lx, Ly, treeSize)<<endl;
    }
    
    // find max height
    ll ret = findResult(treeArr, Lx, Ly, treeSize);
    cout<<ret<<endl;
    return 0;
}