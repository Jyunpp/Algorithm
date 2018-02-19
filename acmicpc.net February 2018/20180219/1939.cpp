//20180219 16:11 ~ 16:54
//same pair can have multiple bridge => remember bridgeNumber twice(bi-directional)
//20180219 17:23 ~ 17:35
//20180219 18:25 ~ 18:31
//20180219 22:20 ~ 22:22
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define xx first
#define yy second

typedef pair<int, int> P;
int n, m, s, e;
int ret = -1;
vector<pair<P, int>> arr[10001];  // {{nodeNum, capacity}, bridgeNum}
int passed[200001];   // bridgeNumber
int visited[10001];   // nodeNumber

void solve();
bool isFlowable(int amount);

int main(){
    cin>>n>>m;
    for(int i=1, a, b, c; i<=m; i++){
        cin>>a>>b>>c;
        arr[a].push_back({{b, c}, i});
        arr[b].push_back({{a, c}, 100000+i});
    }
    cin>>s>>e;
    solve();
    cout<<ret<<endl;
    return 0;
}

bool isFlowable(int amount){
    bool ret = false;
    for(int i=1; i<=m; i++) passed[i] = 0;
    for(int i=100001; i<=100000+m; i++) passed[i] = 0;
    for(int i=1; i<=n; i++) visited[i] = 0;
    queue<int> q;
    q.push(s);
    visited[s] = 1;
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(auto &i : arr[curr]){
            if(!visited[i.xx.xx]){
                if(!passed[i.yy]){
                    passed[i.yy] = 1;
                    //cout<<"i.xx.yy"<<i.xx.yy<<endl;
                    if(i.xx.yy >= amount){
                        q.push(i.xx.xx);
                        visited[i.xx.xx] = 1;
                        if(i.xx.xx==e) return true;
                    }
                }
            }
        }
    }
    //cout<<"isFlowable("<<amount<<") : "<<ret<<endl;
    return ret;
}

void solve(){
    int lower = 1;
    int upper = 1000000000;
    while(lower<=upper){
        ret = (lower+upper)/2;
        if(isFlowable(ret)){
            lower = ret+1;
        }
        else{
            upper = ret-1;
        }
        //cout<<"ret, lower, upper : "<<ret<<", "<<lower<<", "<<upper<<endl;
    }
    ret = (lower+upper)/2;
}