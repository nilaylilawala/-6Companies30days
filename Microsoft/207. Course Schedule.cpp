class Solution {
public:
    bool dfs(int s, unordered_map<int, list<int>>& adj, vector<int>& vis, vector<int>& dfsVis){
        vis[s] = 1;
        dfsVis[s] = 1;
        for(auto neigh: adj[s]) {
            if(vis[neigh] && dfsVis[neigh]) {
                return true;
            }
            else if(!vis[neigh]) {
                vis[neigh] = 1;
                dfsVis[neigh] = 1;
                bool found = dfs(neigh, adj, vis, dfsVis);
                if(found) return true;
            }
        }
        dfsVis[s] = 0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        int m =prerequisites.size();
        unordered_map<int, list<int>> adj;
        for(int i=0; i<m; i++) {
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        vector<int> vis(numCourses, 0), dfsVis(numCourses, 0);
        for(int i=0; i<numCourses; i++) {
            if(!vis[i]) {
                bool found = dfs(i, adj, vis, dfsVis);
                if(found) return false;
            }
        }
        return true;
    }
};
