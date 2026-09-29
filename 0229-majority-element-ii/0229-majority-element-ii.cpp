class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int x1,x2,cnt1,cnt2;
        x1=x2=INT_MIN;
        cnt1=cnt2=0;
        for(int num:nums)
        {
            if(cnt1==0 && num!=x2) x1=num;
            else if(cnt2==0 && num!=x1) x2=num;
            //now comparison part
            if(x1==num) ++cnt1;
            else if(x2==num) ++cnt2;
            else
            {
                --cnt1;
                --cnt2;
            }
        }
        cnt1=0;
        cnt2=0;
        for(int num:nums)
        {
            if(num==x1) ++cnt1;
            if(num==x2) ++cnt2;
        }
        vector<int> ans;
        if(cnt1>(nums.size()/3)) ans.push_back(x1);
        if(cnt2>(nums.size()/3)) ans.push_back(x2);
        return ans;
    }
};