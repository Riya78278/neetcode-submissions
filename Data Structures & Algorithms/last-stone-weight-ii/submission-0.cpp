class Solution {
private:
    int solve (vector<int>&stones,int target,int sum){
        int n=stones.size();
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));

        for(int i=0;i<n+1;i++){
            for(int j=0;j<target+1;j++){
                if(i==0){
                    dp[i][j]=0;
                }
                if(j==0){
                    dp[i][j]=1;
                }
            }
        }

        for(int i=1;i<n+1;i++){
            for(int j=1;j<target+1;j++){
                if(stones[i-1]<=j){
                    dp[i][j]=max(stones[i-1]+dp[i-1][j-stones[i-1]],dp[i-1][j]);
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }

        int s1=dp[n][target];
        int s2=sum-s1;
        return abs(s2-s1);
    }    
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum=0;
        for(int i=0;i<stones.size();i++){
            sum +=stones[i];
        }
        return solve(stones,sum/2,sum);
    }
};