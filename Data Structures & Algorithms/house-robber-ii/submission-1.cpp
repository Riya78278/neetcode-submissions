class Solution {
private:
    int solve(int i, int n, vector<int>& nums, vector<int>& dp) {
        if(i >= n) {
            return 0;
        }

        if(dp[i] != -1) {
            return dp[i];
        }

        int rob = nums[i] + solve(i + 2, n, nums, dp);
        int notRob = solve(i + 1, n, nums, dp);

        return dp[i] = max(rob, notRob);
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) {
            return nums[0];
        }

        vector<int> dp(n, -1);

        // Case 1: Don't rob the last house
        int first = solve(0, n - 1, nums, dp);

        // Reset dp for the second case
        fill(dp.begin(), dp.end(), -1);

        // Case 2: Don't rob the first house
        int second = solve(1, n, nums, dp);

        return max(first, second);
    }
};