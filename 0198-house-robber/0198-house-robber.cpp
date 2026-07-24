class Solution {
public:
    unordered_map<int,int> mp;
    int solve(vector<int>& nums,int idx)
    {
        if(idx>=nums.size()) return 0;
        if(mp.count(idx)) return mp[idx];
        int pick=nums[idx]+solve(nums,idx+2);
        int nopick=solve(nums,idx+1);
        return mp[idx]=max(pick,nopick);
    }
    int rob(vector<int>& nums) {
        return solve(nums,0);
    }
};