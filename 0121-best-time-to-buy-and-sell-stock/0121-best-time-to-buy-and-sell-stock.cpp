class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int bestBuy,profit,ans;
        bestBuy=INT_MAX;
        ans=profit=0;
        for(int x:prices)
        {
            if(x<bestBuy) bestBuy=x;
            else profit=x-bestBuy;
            ans=max(ans,profit);
        }
        return ans;
    }
};