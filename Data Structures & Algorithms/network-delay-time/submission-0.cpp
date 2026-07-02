class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n + 1);

        for(auto it : times){
            int u = it[0];
            int v = it[1];
            int w = it[2];

            adj[u].push_back({v,w});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int> distance(n + 1, INT_MAX);

        distance[k]=0;
        pq.push({0,k});

        while(!pq.empty()){
            auto node=pq.top().second;
            int dist=pq.top().first;

            pq.pop();
            for(auto it:adj[node]){
                int val=it.first;
                int weight=it.second;

                if(dist+weight<distance[val]){
                    distance[val]=dist+weight;
                    pq.push({dist+weight,val});
                }
                
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            ans=max(ans,distance[i]);
        }
        return (ans==INT_MAX)? -1:ans;
        
    }
};
