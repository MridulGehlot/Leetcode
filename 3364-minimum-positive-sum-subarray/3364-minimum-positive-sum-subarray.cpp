class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int ans=INT_MAX;
        for(int i=0;i<nums.size();++i)
        {
            int sum=0;
            for(int j=i;j<nums.size() && j<(i+r);++j)
            {
                int sz=j-i+1;
                sum+=nums[j];
                if(sz>=l && sum>0) ans=min(ans,sum);
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};