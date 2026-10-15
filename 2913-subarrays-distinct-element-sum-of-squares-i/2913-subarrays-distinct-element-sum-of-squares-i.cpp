class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();++i)
        {
            unordered_set<int> st;
            for(int j=i;j<nums.size();++j)
            {
                //consider subarray from i..j
                st.insert(nums[j]);
                //cout<<st.size()<<endl;
                sum+=pow(st.size(),2);
            }
        }
        return sum;
    }
};