//20180216 17:35 ~ 18:09
#include <iostream>
#include <queue>
using namespace std;

#define xx first;
#define yy second;

typedef pair<int,int> P;
int k,w,h;
int arr[201][201];
int visited[201][201][201];
int dy[12] = {1, 0, -1, 0, 2, 2, 1, -1, -2, -2, -1, 1};
int dx[12] = {0, 1, 0, -1, -1, 1, 2, 2, 1, -1, -2, -2};

int main() {
    cin>>k>>w>>h;
    for(int i=1; i<=h; i++){
        for(int j=1; j<=w; j++){
            cin>>arr[i][j];
        }
    }
    visited[1][1][k] = 1;
    queue<pair<P, int>> q;
    q.push({{1,1}, k});
    int ret= 0;
    bool ended = false;
    while(!q.empty()){
        int sz = q.size();
        //cout<<"test"<<endl;
        while(sz--){
            P currP = q.front().xx;
            int y = currP.yy;
            int x = currP.xx;
            int currK = q.front().yy;
            //cout<<"test y,x : "<<y<<", "<<x<<endl;
            q.pop();
            if(y==h && x==w) {
                ended = true;
                break;
            }
            for(int i=0; i<4; i++){
                int ny = y + dy[i];
                int nx = x + dx[i];
                if(ny>0 && nx>0 && ny<=h && nx<=w){
                    if(visited[ny][nx][currK]==0 && arr[ny][nx] !=1){
                        visited[ny][nx][currK] = 1;
                        q.push({{nx, ny}, currK});
                    }
                }
            }
            if(currK>0){
                for(int i=4; i<12; i++){
                    int ny = y + dy[i];
                    int nx = x + dx[i];
                    if(ny>0 && nx>0 && ny<=h && nx<=w){
                        if(visited[ny][nx][currK-1]==0 && arr[ny][nx] !=1){
                            visited[ny][nx][currK-1] = 1;
                            q.push({{nx, ny}, currK-1});
                        }
                    }
                }
            }
        }
        if(ended) break;
        ret++;
    }
    if(ended) cout<<ret<<endl;
    else cout<<-1<<endl;
    return 0;
}