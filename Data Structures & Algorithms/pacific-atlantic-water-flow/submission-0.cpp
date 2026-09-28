class Solution {
private:
    void dfs(vector<vector<int>>& heights,int i,int j,int previousval,vector<vector<bool>>&visited,int delrow[],int delcol[]){
        int n=heights.size();
        int m=heights[0].size();

        if(i<0 || i>=n || j<0 || j>=m){
            return ;
        }
        if(heights[i][j]<previousval || visited[i][j]==true){
            return ;
        }
        visited[i][j]=true;
        for(int it=0;it<4;it++){
            int nrow=i+delrow[it];
            int ncol=j+delcol[it];

            dfs(heights,nrow,ncol,heights[i][j],visited,delrow,delcol);
        }

    }    
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();

        vector<vector<bool>>pacific(n,vector<bool>(m,false));
        vector<vector<bool>>atlantic(n,vector<bool>(m,false));

        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};

        for(int j=0;j<m;j++){
            dfs(heights,0,j,INT_MIN,pacific,delrow,delcol);
            dfs(heights,n-1,j,INT_MIN,atlantic,delrow,delcol);
        }

        for(int i=0;i<n;i++){
            dfs(heights,i,0,INT_MIN,pacific,delrow,delcol);
            dfs(heights,i,m-1,INT_MIN,atlantic,delrow,delcol);
        }

        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pacific[i][j]==true && atlantic[i][j]==true ){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};
