class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt,x;
        cnt=0;
        for(int num:nums)
        {
            if(cnt==0)
            {
                x=num;
                cnt=0;
            }
            if(num==x) ++cnt;
            else --cnt;
        }
        return x;
    }
};