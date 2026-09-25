class Solution {
private:
    void bfs(int i,int j,vector<vector<int>>&vis,vector<vector<char>>& grid){
        vis[i][j]=1;
        queue<pair<int,int>>q;
        int n=grid.size();
        int m=grid[0].size();

        q.push({i,j});
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();

            int delrow[] = {-1,0,1,0};
int delcol[] = {0,1,0,-1};

for(int k=0;k<4;k++){
    int nrow = r + delrow[k];
    int ncol = c + delcol[k];

    if(nrow>=0 && nrow<n &&
       ncol>=0 && ncol<m &&
       !vis[nrow][ncol] &&
       grid[nrow][ncol]=='1'){

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
                    bfs(i,j,vis,grid);
                }
            }
        }
        return count;
        
    }
};

