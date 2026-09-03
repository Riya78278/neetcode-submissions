#include <vector>
#include <cstring>
using namespace std;

class Solution {
    int dp[101][101];

    int func(int i, int j, int n, int m) {
        // Out of bounds
        if (i >= n || j >= m) {
            return 0;
        }

        // Destination
        if (i == n-1 && j == m-1) {
            return 1;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int down = func(i+1, j, n, m);
        int right = func(i, j+1, n, m);

        return dp[i][j] = down + right;
    }

public:
    int uniquePaths(int m, int n) {
        memset(dp, -1, sizeof(dp));
        return func(0, 0, m, n);
    }
};