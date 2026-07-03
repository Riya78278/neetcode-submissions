class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<vector<pair<int,int>>>adj(n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int x1=points[i][0];
                int y1=points[i][1];
                int x2=points[j][0];
                int y2=points[j][1];

                int dist=abs(x1-x2)+abs(y1-y2);
                adj[i].push_back({j,dist});
                adj[j].push_back({i,dist});
            }
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<bool>visited(n,false);
        int cost=0;
        pq.push({0,0});

        while(!pq.empty()){
            auto node=pq.top().second;
            int wt=pq.top().first;

            pq.pop();

            if(visited[node]==true) continue;
            cost+= wt;


            visited[node]=true;

            for(auto it:adj[node]){
                auto neighbournode=it.first;
                int neigbourwt=it.second;

                if(visited[neighbournode]==true)continue;
                pq.push({neigbourwt,neighbournode});

            }

        }
        return cost;
    }
};
