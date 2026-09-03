class Solution {
    int dp[101][101] = {};

private:
    int func(int i, int j, int m, int n) {

        // Out of bounds
        if (i >= m || j >= n) {
            return 0;
        }

        // Destination
        if (i == m - 1 && j == n - 1) {
            return 1;
        }

        // Already calculated
        if (dp[i][j] != 0) {
            return dp[i][j];
        }

        int right = func(i, j + 1, m, n);
        int down = func(i + 1, j, m, n);

        return dp[i][j] = right + down;
    }

public:
    int uniquePaths(int m, int n) {
        return func(0, 0, m, n);
    }
};