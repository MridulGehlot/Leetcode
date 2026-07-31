class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows,cols;
        rows=grid.size();
        cols=grid[0].size();
        vector<vector<bool>> vis(rows,vector<bool>(cols,false));
        queue<pair<int,int>> q;
        vector<int> dd={0,1,0,-1,0};
        int cnt=0;
        for(int i=0;i<rows;++i)
        {
            for(int j=0;j<cols;++j)
            {
                if(!vis[i][j] && grid[i][j]=='1')
                {
                    ++cnt;
                    vis[i][j]=true;
                    q.push({i,j});
                    while(!q.empty())
                    {
                        auto [a,b] = q.front();
                        q.pop();
                        for(int k=0;k<4;k++)
                        {
                            int ni=a+dd[k];
                            int nj=b+dd[k+1];
                            if(ni<0 || ni>=rows || nj<0 || nj>=cols) continue;
                            if(vis[ni][nj]==false && grid[ni][nj]=='1')
                            {
                                vis[ni][nj]=true;
                                q.push({ni,nj});
                            }
                        }
                    }
                }
            }
        }
        return cnt;
    }
};