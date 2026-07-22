class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>>vis(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }
            }
        }

        int time=0;
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};

        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int t=q.front().second;

            time=max(time,t);
            q.pop();

            for(int i=0;i<4;i++){
                int row= r+ delrow[i];
                int col= c+delcol[i];

                if(row<n && row >=0 && col <m && col >=0 && grid[row][col]==1 && vis[row][col]!=2){
                    q.push({{row,col},t+1});
                    vis[row][col]=2;
                }
            }
            
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]!=2 && grid[i][j]==1){
                    return -1;
                }
            }
        }
        return time;
    }
};
