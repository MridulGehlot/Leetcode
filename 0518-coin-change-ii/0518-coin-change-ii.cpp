class Solution {
public:
    int solve(int idx,int amt,vector<int>& coins,vector<vector<int>> &dp)
    {
        if(idx<0) return 0;
        if(amt==0) return 1;
        if(dp[idx][amt]!=-1) return dp[idx][amt];
        int take,notake;
        take=notake=0;
        if(coins[idx]<=amt) take=solve(idx,amt-coins[idx],coins,dp);
        notake=solve(idx-1,amt,coins,dp);
        return dp[idx][amt] = take+notake;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        return solve(coins.size()-1,amount,coins,dp);
    }
};