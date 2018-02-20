//20180220 14:24 ~ 14:57
#include <iostream>
#include <queue>
using namespace std;

#define xx first;
#define yy second;
typedef pair<int, int> P;

int prime[10000];
int visited[10000];
int t, n;

void preprocess(){
    for(int i=2; i<=9999; i++){
        prime[i] = 1;
    }
    for(int i=2; i*i<=9999; i++){
        for(int j=i*2; j<=9999; j+=i){
            prime[j] = 0;
        }
    }
}

int solve(int a, int b){
    if(a==b){return 0;}
    for(int i=1; i<=9999; i++) visited[i] = 0;
    queue<P> q;
    q.push({a, 0});
    visited[a] = 1;
    while(!q.empty()){
        int currNum = q.front().xx;
        int currCnt = q.front().yy;
        //cout<<"currNum, Cnt : "<<currNum<<", "<<currCnt<<endl;
        if(currNum==b) return currCnt;
        q.pop();
        for(int i=1; i<=1000; i*=10){
            int currBase = ((currNum/(i*10))*i*10 + currNum%i);
            //cout<<"currNum , currbase : "<<currNum<<", "<<currBase<<endl;
            for(int j=0; j<10; j++){
                int curr = currBase + i*j;
                if(curr<=999 || curr>9999) continue;
                if(!visited[curr]){
                    visited[curr] = 1;
                    if(prime[curr]) q.push({curr, currCnt+1});
                }
            }
        }
    }
    return -1;
}

int main(){
    cin>>t;
    preprocess();
    for(int i=1, a, b; i<=t; i++){
        cin>>a>>b;
        //cout<<"TestCase #"<<i<<endl;
        int ret = solve(a, b);
        if(ret !=-1) cout<<ret<<endl;
        else cout<<"Impossible"<<endl;
    }
    return 0;
}