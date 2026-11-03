class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxi=*max_element(nums.begin(),nums.end());
        int cost=0;
        for(int x:nums) cost+=maxi-x;
        return cost;
    }
};