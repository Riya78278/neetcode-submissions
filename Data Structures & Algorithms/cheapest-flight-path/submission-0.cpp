class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto it:flights){
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            adj[u].push_back({v,wt});
        }

        queue<pair<int,pair<int,int>>>q;
        vector<int>dist(n,1e9);
        q.push({0,{src,0}});//step,src,cost
        dist[src]=1;

        while(!q.empty()){
            int step=q.front().first;
            int node=q.front().second.first;
            int cost=q.front().second.second;
            q.pop();

            for(auto it:adj[node]){
                int v=it.first;
                int wt=it.second;

                if(cost+wt<dist[v] && step<=k){
                    dist[v]=cost+wt;
                    q.push({step+1,{v,dist[v]}});
                }
            }
        }
        if(dist[dst]==1e9){
            return -1;
        }
        return dist[dst];
    }

};