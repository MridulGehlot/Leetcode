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
    bool ans;
    bool isSame(TreeNode* root, TreeNode* subRoot)
    {
        if(!root && !subRoot) return true;
        if(!root || !subRoot) return false;
        if(root->val != subRoot->val) return false;
        return isSame(root->left,subRoot->left) && isSame(root->right,subRoot->right);
    }
    void traverse(TreeNode* root, TreeNode* subRoot)
    {
        if(!root || ans) return;
        if(root->val==subRoot->val)
        {
            if(isSame(root,subRoot)) ans=true;
        }
        traverse(root->left,subRoot);
        traverse(root->right,subRoot);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        ans=false;
        traverse(root,subRoot);
        return ans;
    }
};