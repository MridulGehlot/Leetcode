class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<int> adj[n];
        for(auto &p:invocations)
        {
            adj[p[0]].push_back(p[1]);
        }
        vector<bool> vis(n,false);
        queue<int> q;
        q.push(k);
        vis[k]=true;
        while(!q.empty())
        {
            auto node=q.front();
            q.pop();
            for(auto &x:adj[node])
            {
                if(!vis[x])
                {
                    vis[x]=true;
                    q.push(x);
                }
            }
        }
        vector<int> ans;
        bool flag=false;
        for(int i=0;i<n;++i)
        {
            if(!vis[i])
            {
                for(auto &x:adj[i])
                {
                    if(vis[x]) flag=true;
                }
            }
            if(flag) break;
        }
        if(flag) for(int i=0;i<n;++i) ans.push_back(i);
        else for(int i=0;i<n;++i) if(!vis[i]) ans.push_back(i);
        return ans;
    }
};