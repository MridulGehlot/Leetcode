class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int x,y;
        x=y=INT_MIN;
        for(int a:nums)
        {
            if(a>x)
            {
                y=x;
                x=a;
            }
            else if(a>y)
            {
                y=a;
            }
        }
        return (x-1)*(y-1);
    }
};