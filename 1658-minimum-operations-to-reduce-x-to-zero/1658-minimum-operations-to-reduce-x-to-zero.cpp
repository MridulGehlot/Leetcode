class Solution {
public:
    /*
    int ans;
    void solve(vector<int>& nums, int x,int i,int j,int sum,int steps)
    {
        if(i>j) return;
        if(sum>x) return;
        if(sum==x)
        {
            ans=min(ans,steps);
            return;
        }
        //pick left
        solve(nums,x,i+1,j,sum+nums[i],steps+1);
        //pick right
        solve(nums,x,i,j-1,sum+nums[j],steps+1);
    }
    */
    int minOperations(vector<int>& nums, int x) {
        //ans=INT_MAX;
        //solve(nums,x,0,nums.size()-1,0,0);
        //return ans==INT_MAX?-1:ans;
        int l,r;
        int maxi_distance=0;
        int n=nums.size();
        int total_sum=accumulate(nums.begin(),nums.end(),0);
        int sum_to_form=total_sum-x;
        if(sum_to_form<0) return -1;
        if(sum_to_form==0) return n;
        int sum=0;
        l=r=0;
        while(r<n)
        {
            sum+=nums[r];
            while(l<n && sum>sum_to_form)
            {
                sum-=nums[l];
                ++l;
            }
            if(sum==sum_to_form)
            {
                maxi_distance=max(maxi_distance,r-l+1);
            }
            ++r;
        }
        if(maxi_distance==0) return -1;
        return n-maxi_distance;
    }
};