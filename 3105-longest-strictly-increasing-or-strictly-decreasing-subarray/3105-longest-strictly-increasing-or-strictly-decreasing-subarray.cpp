class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans,i,j;
        ans=1;
        i=1;
        while(i<nums.size())
        {
            j=i;
            while(j<nums.size() && nums[j]>nums[j-1]) ++j;
            ans=max(ans,j-i+1);
            i=max(i,j-1);
            j=i;
            while(j<nums.size() && nums[j]<nums[j-1]) ++j;
            ans=max(ans,j-i+1);
            i=max(i,j-1);
            while(j<nums.size() && nums[i]==nums[j]) ++j;
            i=max(i,j);
        }
        return ans;
    }
};