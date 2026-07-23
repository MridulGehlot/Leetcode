class Solution {
public:
    int maxArea(vector<int>& height) {
        int l,r,ans,water;
        ans=0;
        l=0;
        r=height.size()-1;
        while(l<r)
        {
            water=min(height[l],height[r])*(r-l);
            ans=max(ans,water);
            if(height[l]<height[r]) l++;
            else r--;
        }
        return ans;
    }
};