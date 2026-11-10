class Solution {
public:
    unordered_map<int,long long> mp;
    long long solve(int i, vector<int>& costs)
    {
        if(i<0) return INT_MAX;
        if(i==0) return 0;
        if(mp.count(i)) return mp[i];
        long long a,b,c;
        a=solve(i-1,costs)+1;
        b=solve(i-2,costs)+4;
        c=solve(i-3,costs)+9;
        return mp[i] = costs[i-1]+min({a,b,c});
    }
    int climbStairs(int n, vector<int>& costs) {
        //return solve(n,costs);
        //The Above Solution Failed We Need to try Iterative DP
        int a,b,c;
        vector<int> dp(n+1,INT_MAX);
        dp[0]=0;
        for(int i=1;i<=n;++i)
        {
            a=b=c=INT_MAX;
            if(i>=1) a=dp[i-1]+1;
            if(i>=2) b=dp[i-2]+4;
            if(i>=3) c=dp[i-3]+9;
            dp[i]=min({a,b,c})+costs[i-1];
        }
        return dp[n];
    }
};