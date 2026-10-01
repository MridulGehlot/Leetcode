class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero,curr,two;
        zero=0;
        two=nums.size()-1;
        curr=0;
        while(curr<=two)
        {
            if(nums[curr]==0) swap(nums[curr],nums[zero++]);
            else if(nums[curr]==2)
            {
                swap(nums[curr],nums[two]);
                --two;
                --curr;
            }
            ++curr;
        }
    }
};