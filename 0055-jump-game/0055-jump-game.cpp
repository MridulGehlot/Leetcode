class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxJump,curr;
        maxJump=0;
        if(nums.size()==1) return true;
        for(int i=0;i<nums.size();i++)
        {
            if(maxJump<i) return false;
            curr=nums[i];
            maxJump=max(maxJump,curr+i);
            if(maxJump>=nums.size()) return true;
        }
        return maxJump>=(nums.size()-1);
    }
};