class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int rows,cols;
        rows=grid.size();
        cols=grid[0].size();
        vector<int> r(rows,0),c(cols,0);
        for(int i=0;i<rows;++i)
        {
            for(int j=0;j<cols;++j)
            {
                if(grid[i][j]) //server
                {
                    r[i]++;
                    c[j]++;
                }
            }
        }
        int ans=0;
        for(int i=0;i<rows;++i)
        {
            for(int j=0;j<cols;++j)
            {
                if((r[i]>1 || c[j]>1) && grid[i][j]) ++ans;
            }
        }
        return ans;
    }
};