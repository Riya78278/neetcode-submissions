class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1){
            return -1;
        }

        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>>vis(n,vector<int>(n,0));

        q.push({{0,0},1});
        vis[0][0]=1;

        int delrow[]={-1,-1,0,1,1,1,0,-1};
        int delcol[]={0,1,1,1,0,-1,-1,-1};

        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int len=q.front().second;
            q.pop();

            if(r==n-1 && c==n-1){
                return len;
            }

            for(int i=0;i<8;i++){
                int row=r +delrow[i];
                int col= c+delcol[i];

                if(row<n && row >=0 && col <n && col>=0 && grid[row][col]==0 && vis[row][col]!=1){
                    q.push({{row,col},len+1});
                    vis[row][col]=1;
                }
            }
        }
        return -1;

    }
};