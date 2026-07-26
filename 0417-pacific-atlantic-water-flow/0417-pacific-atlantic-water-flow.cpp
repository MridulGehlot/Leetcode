class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows,cols;
        rows=heights.size();
        cols=heights[0].size();
        vector<vector<int>> ans;
        vector<vector<bool>> pacificOcean(rows,vector<bool>(cols,false));
        vector<vector<bool>> atlanticOcean(rows,vector<bool>(cols,false));
        //push all top-left(Pacific Ocean) in queue
        queue<pair<int,int>> q;
        for(int i=0;i<cols;i++) 
        {
            pacificOcean[0][i]=true;
            q.push({0,i});
        }
        for(int i=1;i<rows;i++) 
        {
            pacificOcean[i][0]=true;
            q.push({i,0});
        }
        int d[5]={0,1,0,-1,0};
        while(!q.empty())
        {
            auto [i,j]=q.front();
            q.pop();
            for(int k=0;k<4;++k)
            {
                int ni=i+d[k];
                int nj=j+d[k+1];
                if(ni<rows && ni>=0 && nj<cols && nj>=0)
                {
                    if(pacificOcean[ni][nj]) continue;
                    if(heights[ni][nj]>=heights[i][j])
                    {
                        pacificOcean[ni][nj]=true;
                        q.push({ni,nj});
                    }
                }
            }
        }
        //now for bottom-right(Atlantic Ocean)
        for(int i=0;i<cols;++i)
        {
            q.push({rows-1,i});
            atlanticOcean[rows-1][i]=true;
        }
        for(int i=rows-2;i>=0;i--)
        {
            q.push({i,cols-1});
            atlanticOcean[i][cols-1]=true;
        }
        while(!q.empty())
        {
            auto [i,j]=q.front();
            q.pop();
            for(int k=0;k<4;++k)
            {
                int ni=i+d[k];
                int nj=j+d[k+1];
                if(ni<rows && ni>=0 && nj<cols && nj>=0)
                {
                    if(atlanticOcean[ni][nj]) continue;
                    if(heights[ni][nj]>=heights[i][j])
                    {
                        atlanticOcean[ni][nj]=true;
                        q.push({ni,nj});
                    }
                }
            }
        }
        //now check common Paths
        for(int i=0;i<rows;++i)
        {
            for(int j=0;j<cols;++j)
            {
                if(atlanticOcean[i][j] && pacificOcean[i][j]) ans.push_back({i,j});
            }
        }
      return ans;
    }
};