class Solution {
    int dp[101][101];
private:
    int solve(int i,int j,string &s1, string &s2, string &s3){
        int n=s1.size();
        int m=s2.size();
        int N= s3.size();
        bool result=false;
        if(n+m!=N){
            return false;
        }
        if(i==n && j==m && i+j==N){
            return true;
        }
        if(i+j>=N){
            return false;
        }
        if(dp[i][j]!= -1){
            return dp[i][j];
        }

        if(s1[i]==s3[i+j]){
            result= solve(i+1,j,s1,s2,s3);
        }
        
        if(s2[j]==s3[i+j]){
            result= solve(i,j+1,s1,s2,s3);
        }

        return dp[i][j]=result;

    }    
public:
    bool isInterleave(string s1, string s2, string s3) {
        for(int i=0;i<101;i++){
            for(int j=0;j<101;j++){
                dp[i][j]=-1;
            }
         
        }
        return solve(0,0,s1,s2,s3);
    }
};
