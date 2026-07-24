class Solution {
public:
    int findMin(vector<int>& nums) {
        /*
        ALGORITHM
        pick minimum from sorted part 
        and process remaining
        */
        int l,m,h,ans;
        l=0;
        h=nums.size()-1;
        ans=INT_MAX;
        while(l<=h)
        {
            m=(l+h)/2;
            if(nums[l]<=nums[m]) //left part is sorted
            {
                ans=min(nums[l],ans);
                l=m+1;
            }
            else
            {
                ans=min(nums[m],ans);
                h=m-1;
            }
        }
        return ans;
    }
};