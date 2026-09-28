class Solution {
private:
    int dfs(vector<vector<int>>& grid, vector<vector<int>>& vis, int r, int c) {

        vis[r][c] = 1;

        int area = 1;

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        int n = grid.size();
        int m = grid[0].size();

        for(int i = 0; i < 4; i++) {

            int nrow = r + delrow[i];
            int ncol = c + delcol[i];

            if(nrow >= 0 && nrow < n &&
               ncol >= 0 && ncol < m &&
               !vis[nrow][ncol] &&
               grid[nrow][ncol] == 1) {

                area += dfs(grid, vis, nrow, ncol);
            }
        }

        return area;
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        int maxi = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(!vis[i][j] && grid[i][j] == 1) {

                    int area = dfs(grid, vis, i, j);

                    maxi = max(maxi, area);
                }
            }
        }

        return maxi;
    }
};