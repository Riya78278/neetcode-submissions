class Solution {
private:
    int dp[366];
    int solve (vector<int>& days,vector<int>& costs,int n, int i){
        if(i>=n){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }

        //for 1days
        int cost_1=costs[0]+solve(days,costs,n,i+1);

        //for 7 days
        int j=i;
        int maxdays=days[j]+costs[1];

        while(j<n && days[j]<maxdays){
            j++;
        }
        int cost_7=costs[1]+solve(days,costs,n,j);

        // for 30 days
        int k=i;
        int maxidays=days[k]+costs[2];

        while(k<n && days[k]<maxidays){
            k++;
        }
        int cost_30=costs[2]+solve(days,costs,n,k);

        return dp[i]=min({cost_1,cost_7,cost_30});


    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        for(int i=0;i<366;i++){
            dp[i]=-1;
        }
        int n=days.size();
        return solve(days,costs,n,0);
    }
};