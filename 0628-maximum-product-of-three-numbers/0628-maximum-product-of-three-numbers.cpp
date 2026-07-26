class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=INT_MIN;
        int n=nums.size();
        //last 3 (All +ve)
        int prod=nums[n-1]*nums[n-2]*nums[n-3];
        ans=max(ans,prod);
        //last 2 (+ve) & 1-ve so handle that
        if(n>3) prod=nums[n-1]*nums[n-3]*nums[n-4];
        ans=max(ans,prod);
        //last +ve all -ve
        prod=nums[0]*nums[1]*nums[n-1];
        ans=max(ans,prod);
        return ans;       
    }
};