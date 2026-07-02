class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        priority_queue<pair<int, pair<int,int>>,vector<pair<int, pair<int,int>>>,
    greater<pair<int, pair<int,int>>>
> pq;
        vector<vector<int>> dist(n , vector<int>(n , INT_MAX));
        pq.push({grid[0][0],{0,0}});
        int dr[4]={-1,0,1,0};
        int dc[4]={0,1,0,-1};

        dist[0][0]=grid[0][0];
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();

            int wt=it.first;
            int i=it.second.first;
            int j=it.second.second;

            if(i==n-1 && j==n-1)return wt;

            for(int k=0;k<4;k++){
                int nr = i + dr[k];
                int nc = j + dc[k];

                if(nr>=0 && nr<n && nc>=0 && nc<n){
                    int newwt=max(wt,grid[nr][nc]);
                    if(dist[nr][nc]==INT_MAX || newwt<dist[nr][nc]){
                        dist[nr][nc]=newwt;
                        pq.push({newwt,{nr,nc}});
                    }

                }
            }
        }
        return -1;
        
    }
};