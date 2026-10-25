class Solution {
public:
    bool valid;
    void traverse(vector<vector<int>>& grid,int i,int j)
    {
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size()) return;
        if(grid[i][j]!=0) return;
        if(i==0 || i==grid.size()-1 || j==0 || j==grid[0].size()-1) valid=false;
        grid[i][j]=-1;
        traverse(grid,i+1,j);
        traverse(grid,i-1,j);
        traverse(grid,i,j+1);
        traverse(grid,i,j-1);
    }
    int closedIsland(vector<vector<int>>& grid) {
        int cnt=0;
        for(int i=0;i<grid.size();++i)
        {
            for(int j=0;j<grid[0].size();++j)
            {
                if(grid[i][j]==0)
                {
                    valid=true;
                    traverse(grid,i,j);
                    if(valid) ++cnt;
                }
            }
        }
        return cnt;
    }
};