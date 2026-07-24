class Solution {
public:
    int dp[101];
    int solve(vector<int>& nums,int idx,int limit)
    {
        if(idx>=limit) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int pick=nums[idx]+solve(nums,idx+2,limit);
        int nopick=solve(nums,idx+1,limit);
        return dp[idx] = max(pick,nopick);
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        memset(dp,-1,sizeof(int)*101);
        int a=solve(nums,0,nums.size()-1);
        memset(dp,-1,sizeof(int)*101);
        int b=solve(nums,1,nums.size());
        return max(a,b);
    }
};