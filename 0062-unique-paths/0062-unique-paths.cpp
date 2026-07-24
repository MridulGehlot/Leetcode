class Solution {
public:
    int traverse(int i,int j)
    {
        if(i<0 || j<0) return 0;
        if(i==0 && j==0) return 1;
        int ways=0;
        ways+=traverse(i,j-1);
        ways+=traverse(i-1,j);
        return ways;
    }
    int uniquePaths(int m, int n) {
        //return traverse(m-1,n-1);
        vector<vector<int>> dp(m,vector<int>(n,0));
        dp[0][0]=1;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(j>=1) dp[i][j]+=dp[i][j-1];
                if(i>=1) dp[i][j]+=dp[i-1][j];
            }
        }
        return dp[m-1][n-1];
    }
};