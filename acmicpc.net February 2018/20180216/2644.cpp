//20180216 20:38 ~ 20:43
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define xx first;
#define yy second;

int n, x, y, m;
vector<int> arr[101];
int visited[101];
queue<pair<int, int>> q;

int main(){
    cin>>n>>x>>y>>m;
    for(int i=1, a, b; i<=m; i++){
        cin>>a>>b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    q.push({x,0});
    visited[x] = 1;
    int ret = -1;
    while(!q.empty()){
        int currX = q.front().xx;
        int times = q.front().yy;
        q.pop();
        if(currX==y){
            ret = times;
            break;
        }
        for(auto &i : arr[currX]){
            if(visited[i]!=1){
                q.push({i, times+1});
                visited[i] = 1;
            }
        }
    }
    cout<<ret<<endl;
    return 0;
}
