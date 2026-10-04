class Solution {
private:
    int memo(int index,int prev,vector<int>& nums,vector<vector<int>>&dp){
        // base case
        //memoization code
        if(index==nums.size()-1){
            if(prev==-1 || nums[index]>nums[prev]){
                return 1;
            }
            return 0;
        }

        if(dp[index][prev+1]!= -1){
            return dp[index][prev+1];
        }

        int nottake=memo(index+1,prev,nums,dp);
        int take=0;
        if(prev==-1 || nums[index]>nums[prev]){
            take=memo(index+1,index,nums,dp)+1;
        }
        int length=max(take,nottake);
        dp[index][prev+1]=length;
        return dp[index][prev+1];
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return memo(0,-1,nums,dp);
    }
};