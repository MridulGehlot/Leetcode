class Solution {
public:
    bool traverse(int node,vector<int> adj[],vector<bool> &vis,vector<bool> &pathVis)
    {
        vis[node]=true;
        pathVis[node]=true;
        for(auto &n:adj[node])
        {
            if(vis[n] && pathVis[n]) return false;
            if(!vis[n]) if(traverse(n,adj,vis,pathVis)==false) return false;
        }
        pathVis[node]=false;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        for(auto &p:prerequisites) adj[p[1]].push_back(p[0]);
        vector<bool> vis(numCourses,false),pathVis(numCourses,false);
        for(int i=0;i<numCourses;++i)
        {
            if(!vis[i]) if(traverse(i,adj,vis,pathVis)==false) return false;
        }
        return true;
    }
};