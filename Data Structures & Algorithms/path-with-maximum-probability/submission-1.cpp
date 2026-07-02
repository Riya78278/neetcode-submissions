class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int,double>>>adj(n);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            double prob=succProb[i];

            adj[u].push_back({v, prob});
            adj[v].push_back({u, prob});
        }

        vector<double>dist(n,0);
        priority_queue<pair<double,int>>pq;
        dist[start_node]=1.0;
        pq.push({1.0,start_node});
        while(!pq.empty()){
            auto node=pq.top().second;
            double probab=pq.top().first;
            pq.pop();

            for(auto it:adj[node]){
                auto n=it.first;
                double wt=it.second;

                if(probab*wt>dist[n]){
                    dist[n]=probab*wt;
                    pq.push({probab*wt,n});
                }
            }
        }
        return dist[end_node];


    }
};