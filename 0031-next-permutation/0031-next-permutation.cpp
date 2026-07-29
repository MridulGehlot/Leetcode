class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int idx=nums.size()-2;
        while(idx>=0 && nums[idx]>=nums[idx+1]) idx--;
        if(idx==-1)
        {
            sort(nums.begin(),nums.end());
            return;
        }
        int swi=nums.size()-1;
        while(nums[swi]<=nums[idx]) swi--;
        swap(nums[swi],nums[idx]);
        sort(nums.begin()+idx+1,nums.end());
    }
};