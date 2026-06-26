class Solution {
    int dp[101][101][601];
    
private:
    int solve(vector<pair<int,int>>&count,int m,int n,int i){

        if(i>=count.size()){
            return 0;
        }
        if(dp[m][n][i]!= -1){
            return dp[m][n][i];
        }
        if(count[i].first<=m && count[i].second<=n){
            return dp[m][n][i]=max(1+solve(count,m-count[i].first,n-count[i].second,i+1),solve(count,m,n,i+1));
        }
        else {
            return dp[m][n][i]=solve(count,m,n,i+1);
        }
    }    
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        
        for (int i = 0; i <= 100; i++) {
            for (int j = 0; j <= 100; j++) {
                for (int k = 0; k <= 600; k++) {
                    dp[i][j][k] = -1;
                }
            }
        }
        
        int ss=strs.size();
        vector<pair<int,int>>count(ss);

        for(int i=0;i<ss;i++){
            int countzero=0;
            int countone=0;

            for(auto &ch :strs[i]){
                if(ch=='0'){
                    countzero++;
                }
                else{
                    countone++;
                }
            }
            count[i]={countzero,countone};
        }
        return solve(count,m,n,0);
        
    }
};