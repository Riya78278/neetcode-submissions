class Solution {
private:
    void bfs(vector<vector<char>>& grid, vector<vector<int>>&vis,int i,int j){
        vis[i][j]=1;
        queue<pair<int,int>>q;
        q.push({i,j});
        int n=grid.size();
        int m=grid[0].size();
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();

            int delrow[]={-1,0,1,0};
            int delcol[]={0,1,0,-1};

            for(int i=0;i<4;i++){
                int nrow= r+delrow[i];
                int ncol= c+delcol[i];

                if(nrow>=0 && nrow<n && ncol >=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]=='1'){
                    vis[nrow][ncol]=1;
                    q.push({nrow,ncol});

                }
            }
        }
    }    
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
         vector<vector<int>>vis(n,vector<int>(m,0));
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    count++;
                    bfs(grid,vis,i,j);
                }
            }
        }
        return count;
    }
};
