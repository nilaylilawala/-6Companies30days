class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<long long,long long>>adj[n];

        for(auto it : roads){
            int u = it[0];
            int v = it[1];
            int d = it[2];

            adj[u].push_back({v,d});
            adj[v].push_back({u,d});
        }

        vector<long long>dist(n,LONG_MAX);
        vector<int>path(n,0);

        path[0] = 1;
        dist[0] = 0;
        int mod = 1e9+7;

        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>q;
        q.push({0,0});

        while(!q.empty()){
            auto temp = q.top();
            q.pop();
            long long wt = temp.first;
            int node = temp.second;

            for(auto it : adj[node]){
                int child = it.first;
                long long child_wt = it.second;

                if(wt + child_wt < dist[child]){
                    dist[child] = wt + child_wt;
                    path[child] = path[node];
                    q.push({dist[child],child});
                }
                else if(wt + child_wt == dist[child]){
                    path[child] += path[node];
                    path[child] %= mod;
                }
            }
        }
        return path[n-1];
    }
};
