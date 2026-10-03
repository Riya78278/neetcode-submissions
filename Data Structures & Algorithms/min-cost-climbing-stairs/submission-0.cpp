class Solution {
public:
    int mccs(vector<int>& cost, int i, vector<int>& dp) {

        int n = cost.size();

        if (i >= n)
            return 0;

        if (dp[i] != -1)
            return dp[i];

        dp[i] = cost[i] + min(
            mccs(cost, i + 1, dp),
            mccs(cost, i + 2, dp)
        );

        return dp[i];
    }

    int minCostClimbingStairs(vector<int>& cost) {

        int n = cost.size();

        vector<int> dp(n, -1);

        return min(
            mccs(cost, 0, dp),
            mccs(cost, 1, dp)
        );
    }
};
