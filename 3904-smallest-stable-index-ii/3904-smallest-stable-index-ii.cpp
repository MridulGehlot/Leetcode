class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n;
        n=nums.size();
        vector<int> minarr(n,LLONG_MAX);
        minarr[n-1]=nums[n-1];
        for(int i=n-2;i>=0;--i) minarr[i]=min(minarr[i+1],nums[i]);
        int maxi=nums[0];
        int idx=-1,min_score=INT_MAX,score;
        for(int i=0;i<n;++i)
        {
            maxi=max(maxi,nums[i]);
            score=maxi-minarr[i];
            if(score<=k && score<min_score)
            {
                min_score=score;
                idx=i;
                return idx;
            }
        }
        return -1;
    }
};