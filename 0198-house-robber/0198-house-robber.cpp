class Solution {
public:
    unordered_map<int,int> mp;
    int solve(vector<int>& nums,int idx)
    {
        if(mp.count(idx)) return mp[idx];
        int a,b;
        a=b=0;
        for(int i=idx;i<nums.size();i++)
        {
            a=max(a,nums[i]+solve(nums,i+2));
            b=max(b,solve(nums,i+1));
        }
        return mp[idx] = max(a,b);
    }
    int rob(vector<int>& nums) {
        /*
        vector<int> dp(nums.size(),0);
        //return solve(nums,0);
        int a,b;
        a=b=0;
        for(int i=0;i<nums.size();++i)
        {
            a=nums[i];
            if(i>1) a+=dp[i-2];
            if(i>0) b=dp[i-1];
            dp[i]=max(a,b);
        }
        return dp[nums.size()-1];
        */
        int prev1,prev2;
        prev1=prev2=0;
        for(int x:nums)
        {
            int curr=max(prev1,prev2+x);
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }
};