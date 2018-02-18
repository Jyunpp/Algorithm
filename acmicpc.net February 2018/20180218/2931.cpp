//20180217 14:38 ~ 14:45
//20180217 19:38 ~ 20:15
//20180218 22:37 ~ 22:56
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int r, c;
int arr[26][26]; //arr[r][c]
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
char shapeArr[8] = {'.', '|', '-', '+', '1', '2', '3', '4'};

struct Pipe {
    char type;
    vector<int> flowable;
};
Pipe pipeArr[8];

pair<int, int> findBlank(){
    for(int i=1; i<=r; i++){
        for(int j=1; j<=c; j++){
            if(arr[i][j] != 0 && arr[i][j] != 10){
                int curr = arr[i][j];
                for( auto &k : pipeArr[curr].flowable){
                    //next
                    int ny = i + dy[k];
                    int nx = j + dx[k];
                    if(ny==0||nx==0||ny>r||nx>c) continue;
                    if(arr[ny][nx]==0) return {ny, nx};
                }
            }
        }
    }
    return {-1,-1}; //can't reach here.
}

int main(){
    cin>>r>>c;
    for(int i=1; i<=r; i++){
        for(int j=1; j<=c; j++){
            char ch;
            cin>>ch;
            arr[i][j] = 0;          //'.'
            if(ch!='M' && ch!='Z'){
                for(int k=1; k<=7; k++){
                    if(shapeArr[k]==ch){
                        arr[i][j] = k;
                        break;
                    }
                }
            }
            else arr[i][j] = 10;    //'M' or 'Z'
        }
    }

    pipeArr[1].type = '|'; pipeArr[1].flowable.push_back(0); pipeArr[1].flowable.push_back(2);
    pipeArr[2].type = '-'; pipeArr[2].flowable.push_back(1); pipeArr[2].flowable.push_back(3);
    pipeArr[3].type = '+'; pipeArr[3].flowable.push_back(0); pipeArr[3].flowable.push_back(1); pipeArr[3].flowable.push_back(2); pipeArr[3].flowable.push_back(3);
    pipeArr[4].type = '1'; pipeArr[4].flowable.push_back(1); pipeArr[4].flowable.push_back(2);
    pipeArr[5].type = '2'; pipeArr[5].flowable.push_back(0); pipeArr[5].flowable.push_back(1);
    pipeArr[6].type = '3'; pipeArr[6].flowable.push_back(0); pipeArr[6].flowable.push_back(3);
    pipeArr[7].type = '4'; pipeArr[7].flowable.push_back(3); pipeArr[7].flowable.push_back(2);
    
    pair<int, int> blank = findBlank();
    int by = blank.first;
    int bx = blank.second;
    vector<int> blankFlowable;
    for(int i=0; i<4; i++){
        int ny = by + dy[i];
        int nx = bx + dx[i];
        int curr = arr[ny][nx];
        if(curr!=10 && curr!=0){
            for(auto &j : pipeArr[curr].flowable){
                if(ny+dy[j]==by && nx+dx[j]==bx){
                    blankFlowable.push_back((i+g2)%4);
                    break;
                }
            }
        }
        else if(curr==10){
            blankFlowable.push_back((i+2)%4);
        }
    }
    int pipeIdx;
    for(int i=1; i<=7; i++){
        bool isSame = true;
        if(blankFlowable.size()==pipeArr[i].flowable.size()){
            for(auto &j : pipeArr[i].flowable){
                if(find(blankFlowable.begin(), blankFlowable.end() ,(j+2)%4) == blankFlowable.end()){
                    isSame = false;
                    break;
                }
            }
        }
        else{
            isSame = false;
        }
        if(isSame) {
            pipeIdx = i;
            break;
        }
    }

    cout<<by<<" "<<bx<<" "<<shapeArr[pipeIdx]<<endl;
    return 0;
}