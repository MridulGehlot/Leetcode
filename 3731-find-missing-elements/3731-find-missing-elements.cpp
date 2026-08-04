class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int maxi,mini;
        maxi=mini=nums[0];
        for(int x:nums)
        {
            maxi=max(maxi,x);
            mini=min(mini,x);
        }
        vector<int> space(maxi-mini+1,-1);
        vector<int> ans;
        for(int x:nums) space[x-mini]=1;
        for(int i=0;i<space.size();++i) if(space[i]==-1) ans.push_back(mini+i); 
        return ans;
    }
};