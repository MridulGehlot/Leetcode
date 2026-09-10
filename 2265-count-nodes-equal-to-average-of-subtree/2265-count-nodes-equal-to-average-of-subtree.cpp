/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int cnt;
    pair<int,int> traverse(TreeNode *root)
    {
        if(!root) return {0,0};
        auto [l,lcnt]=traverse(root->left);
        auto [r,rcnt]=traverse(root->right);
        int sum=l+r+root->val;
        int n=lcnt+rcnt+1;
        int avg=sum/n;
        if(avg==root->val) ++cnt;
        return {sum,n};
    }
    int averageOfSubtree(TreeNode* root) {
        cnt=0;
        traverse(root);
        return cnt;
    }
};