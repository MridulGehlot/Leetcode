class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int>& candidates, int &target,int idx,vector<int> &v,int sum)
    {
        if(idx>=candidates.size() || sum>target) return;
        if(sum==target)
        {
            ans.push_back(v);
            return;
        }
        v.push_back(candidates[idx]);
        solve(candidates,target,idx,v,sum+candidates[idx]);
        v.pop_back();
        solve(candidates,target,idx+1,v,sum);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> v;
        solve(candidates,target,0,v,0);
        return ans;
    }
};