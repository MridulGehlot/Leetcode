class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int maxi=1,curr=1;
        int currSum=nums[0],maxiSum=nums[0];
        for(int i=1;i<nums.size();++i)
        {
            if(nums[i]!=nums[i-1]+1) break;
            currSum+=nums[i];
            ++curr;
            if(curr>maxi || (curr==maxi && currSum>maxiSum))
            {
                maxi=curr;
                maxiSum=currSum;
            }
        }
        vector<int> temp(51,0);
        for(int x:nums) temp[x]=1;
        int x=maxiSum;
        while(x<=50 && temp[x]==1) ++x;
        return x;
    }
};