class Solution {
public:
    int N;
    unordered_map<int,int> mp;
    int solve(int i,vector<int> &prefixSum)
    {
        if(i==N-1)
        {
            return prefixSum[N-1];
        }
        if(mp.count(i)) return mp[i];
        int take=prefixSum[i]-solve(i+1,prefixSum);
        int skip=solve(i+1,prefixSum);
        return mp[i]=max(take,skip);
    }
    int stoneGameVIII(vector<int>& stones) {
        /*
        int n=stones.size();
        N=n;
        vector<int> prefixSum(n,0);
        prefixSum[0]=stones[0];
        for(int i=1;i<n;++i) prefixSum[i]=prefixSum[i-1]+stones[i];
        return solve(1,prefixSum);
        */
        int n=stones.size();
        vector<int> dp(n,0);
        vector<int> prefixSum(n,0);
        prefixSum[0]=stones[0];
        for(int i=1;i<n;++i) prefixSum[i]=prefixSum[i-1]+stones[i];
        dp[n-1]=prefixSum[n-1];
        for(int i=n-2;i>0;--i)
        {
            int take=prefixSum[i]-dp[i+1];
            int skip=dp[i+1];
            dp[i]=max(take,skip);
        }
        return dp[1];
    }
};