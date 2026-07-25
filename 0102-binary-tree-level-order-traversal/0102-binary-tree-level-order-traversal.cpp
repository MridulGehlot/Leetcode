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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> ans;
        queue<TreeNode *> q;
        q.push(root);
        TreeNode *x;
        while(!q.empty())
        {
            vector<int> v;
            int sz=q.size();
            for(int i=0;i<sz;++i)
            {
                x=q.front();
                q.pop();
                v.push_back(x->val);
                if(x->left) q.push(x->left);
                if(x->right) q.push(x->right);
            }
            ans.push_back(v);
        }
        return ans;
    }
};