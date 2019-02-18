// 20190218 20:30 ~ 20:58
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
#define rep(i, l, r) for(int i=l; i<r; i++)
#define sortV(v, lambda) sort(v.begin(), v.end(), lambda)
#define powll(a, b) (ll) pow(a, b)

typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> Pll;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root) return ;
        if(root->left && root->right) {
            flatten(root->left);
            TreeNode *leftHead = root->left;
            TreeNode *leftLeaf = root->left;
            while(leftLeaf->right) leftLeaf = leftLeaf->right;
            leftLeaf->right = root->right;
            root->right = leftHead;
            root->left = NULL;
            flatten(root->right);
        } else if(root->left) {
            root->right = root->left;
            root->left = NULL;
            flatten(root->right);
        } else if(root->right) flatten(root->right);
    }
};

int main() {
    Solution solution;
    TreeNode root = TreeNode(2);
    TreeNode rootl = TreeNode(1);
    TreeNode rootr = TreeNode(4);
    // TreeNode rootll = TreeNode(3);
    // TreeNode rootlr = TreeNode(4);
    // TreeNode rootrr = TreeNode(6);
    TreeNode rootrl = TreeNode(3);
    root.left = &rootl;
    root.right = &rootr;
    root.right->left = &rootrl;
    // root.right->right = &rootrr;
    // root.left->left = &rootll;
    // root.left->right = &rootlr;
    solution.flatten(&root);

    cout<<root.val;
    while(root.right) {
        root = *(root.right);
        cout<<","<<root.val;
    }
    return 0;
}