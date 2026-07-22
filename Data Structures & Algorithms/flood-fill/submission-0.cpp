class Solution {
private:
    void dfs(vector<vector<int>>&ans,vector<vector<int>>&vis,int sr,int sc,int newcolor,int delrow[],int delcol[],int inicolor){
        int n=ans.size();
        int m=ans[0].size();
        vis[sr][sc]=1;
        ans[sr][sc]=newcolor;

        for(int i=0;i<4;i++){
            int r=sr+delrow[i];
            int c=sc+delcol[i];

            if(r<n && r>=0 && c<m && c>=0 && !vis[r][c] && ans[r][c]== inicolor){
                dfs(ans,vis,r,c,newcolor,delrow,delcol, inicolor);
            }
        }
    }    
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        int inicolor=image[sr][sc];
        vector<vector<int>>ans=image;
        vector<vector<int>>vis(n,vector<int>(m,0));
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        dfs(ans,vis,sr,sc,color,delrow,delcol,inicolor);
        return ans;
    }
};