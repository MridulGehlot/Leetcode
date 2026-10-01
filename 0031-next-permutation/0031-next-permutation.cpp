class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int dip;
        dip=nums.size()-2;
        while(dip>=0 && nums[dip]>=nums[dip+1]) --dip;
        if(dip==-1)
        {
            reverse(nums.begin(),nums.end());
            return;
        }
        int i=nums.size()-1;
        while(i>dip && nums[i]<=nums[dip]) --i;
        swap(nums[i],nums[dip]);
        reverse(nums.begin()+dip+1,nums.end());
    }
};