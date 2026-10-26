class Solution {
public:
    long long sum;
    void traverse(vector<vector<int>>& grid,int i,int j)
    {
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size()) return;
        if(grid[i][j]==0) return;
        sum+=grid[i][j];
        grid[i][j]=0;
        traverse(grid,i+1,j);
        traverse(grid,i-1,j);
        traverse(grid,i,j+1);
        traverse(grid,i,j-1);
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int cnt=0;
        for(int i=0;i<grid.size();++i)
        {
            for(int j=0;j<grid[0].size();++j)
            {
                if(grid[i][j])
                {
                    sum=0;
                    traverse(grid,i,j);
                    if(sum%k==0) ++cnt;
                }
            }
        }
        return cnt;
    }
};