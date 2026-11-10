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
    int sum;
    int traverse(TreeNode *root)
    {
        if(!root) return 0;
        int l=traverse(root->left);
        int r=traverse(root->right);
        int tilt = abs(l-r);
        sum+=tilt;
        return root->val+l+r;
    }
    int findTilt(TreeNode* root) {
        sum=0;
        traverse(root);
        return sum;
    }
};