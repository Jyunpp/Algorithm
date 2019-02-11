#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int visited[100001];
    int size;
    string str;
    vector<string> words;

    int recur(int currIdx) {
        if(currIdx == size) return true;
        if(visited[currIdx]) return false;

        int ret = 0;
        for(string s : words) {
            if (str.substr(currIdx, s.size()) == s) {
                ret += recur(currIdx+s.size());
            }
        }
        visited[currIdx] = 1;
        return ret;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        size = s.size();
        str = s;
        words = wordDict;
        return recur(0);
    }
};

int main(){
    string s;
    vector<string> v;
    cin>>s;
    int a;
    cin>>a;
    for(int i=1; i<=a; i++) {
        string str;
        cin>>str; v.push_back(str);
    }
    Solution solution;
    cout<<solution.wordBreak(s, v)<<endl;
    return 0;
}