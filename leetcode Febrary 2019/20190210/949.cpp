#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> v;
    int ret = -1;

    void swap(int i, int j) {
        int temp = v[i];
        v[i] = v[j];
        v[j] = temp;
    }

    void permu(int size, int remain) {
        if(remain == 1) {
            int curr = 0;
            for(auto i : v) {
                curr*=10;
                curr+= i;
            }
            if(curr<=2359 && curr % 100 <= 59 && ret < curr ) ret = curr;
        }
        for(int i=0; i<remain; i++) {
            swap(i, remain-1);
            permu(size, remain-1);
            swap(i, remain-1);
        }
    }

    string largestTimeFromDigits(vector<int>& A) {
        v = A;
        permu(A.size(), A.size());

        if(ret == -1) {
            cout<<"";
            return "";
        }
        else {
            int iter = 1000;
            string result = "";
            while(iter) {
                int curr = (ret / iter) % 10;
                result += '0' + curr;
                iter /= 10;
                if(iter == 10) result += ":";
            }
            cout<<result;
            return result;
        }
    }
};

int main(){
    vector<int> v;
    for(int i=1, a; i<=4; i++) {
        cin>>a; v.push_back(a);
    }
    Solution solution;
    solution.largestTimeFromDigits(v);
    return 0;
}