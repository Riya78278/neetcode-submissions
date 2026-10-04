class Solution {
private:
    int dp[302][302];

    int mcm(vector<int>& nums, int i, int j) {

        if (i > j) {
            return 0;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int maxCoins = 0;

        for (int k = i; k <= j; k++) {

            int coins = nums[i - 1] * nums[k] * nums[j + 1]
                      + mcm(nums, i, k - 1)
                      + mcm(nums, k + 1, j);

            maxCoins = max(maxCoins, coins);
        }

        return dp[i][j] = maxCoins;
    }

public:
    int maxCoins(vector<int>& nums) {

        int n = nums.size();

        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        // Initialize DP with -1
        for (int i = 0; i < 302; i++) {
            for (int j = 0; j < 302; j++) {
                dp[i][j] = -1;
            }
        }

        return mcm(nums, 1, n);
    }
};