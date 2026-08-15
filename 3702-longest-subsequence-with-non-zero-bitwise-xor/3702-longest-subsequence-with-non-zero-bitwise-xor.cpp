class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int val=0;
        int n=nums.size();
        for(int x:nums) val^=x;
        if(val) return n;
        for(int i=0;i<n;++i)
        {
            val^=nums[i];
            if(val) return n-1;
            val^=nums[i];
        }
        return 0;
    }
};