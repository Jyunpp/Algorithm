// 20180408 03:11 ~ 03:39
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

int T, D;
string p;

int damage(int len, string p){
    int curr = 1, ret = 0;
    for(int i=0; i<len; i++){
        if(p[i]=='C') curr*=2;
        else ret += curr;
    }
    return ret;
}

int minDamage(int len, int c){
    return len-c;
}

int solve(int D, string p){
    int c=0, s=0, len = p.length(), ret = 0;
    for(int i=0; i<len; i++){
        if(p[i]=='C') c++;
        else s++;
    }
    if(minDamage(len, c)>D) return -1;

    int currDamage = damage(len, p);
    while(currDamage>D){
        int currIdx = len-1;
        // actually currIdx can't reach 0.. because I excepted IMPOSSIBLE 
        while(!(p[currIdx]=='S' && p[currIdx-1]=='C')) currIdx--;
        p[currIdx]='C';
        p[currIdx-1]='S';
        currDamage = damage(len, p);
        ret++;
    }
    return ret;
}

int main(){
    cin>>T;
    for(int i=1; i<=T; i++){
        cin>>D>>p;
        int ret = solve(D, p);
        cout<<"Case #"<<i<<": ";
        if(ret==-1) cout<<"IMPOSSIBLE";
        else cout<<ret;
        if(i!=T) cout<<endl;
    }
}