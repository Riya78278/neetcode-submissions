class Solution {
private:
    int memo(int index,vector<int>& prices,vector<vector<int>>&dp,int buy){
        int n=prices.size();
        if(index>=n ){
            return 0;
        }
        if(dp[index][buy]!= -1){
            return dp[index][buy];
        }
        int profit=0;
        if(buy==1){
            int buyit=-prices[index]+memo(index+1,prices,dp,0);
            int dontbuy=0+memo(index+1,prices,dp,1);
            profit=max(buyit,dontbuy);

        }
        else{
            int sellit=prices[index]+memo(index+2,prices,dp,1);
            int dontsell=0+memo(index+1,prices,dp,0);
            profit=max(sellit,dontsell);
        }
        return dp[index][buy]=profit;
    }    
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n+2,vector<int>(2,-1));
        return memo(0,prices,dp,1);

        

    }
};