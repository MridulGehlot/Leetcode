class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        sort(nums.begin(),nums.end(),[](int a,int b){
            return abs(a)<abs(b);
        });
        long long left_half=0;
        for(int i=0;i<nums.size()/2;++i)
        {
            left_half+=pow(nums[i],2);
        }
        long long right_half=0;
        for(int i=nums.size()/2;i<nums.size();++i)
        {
            right_half+=pow(nums[i],2);
        }
        return right_half-left_half;
    }
};