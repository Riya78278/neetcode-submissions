class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=1;
        int maxi=0;
        if(nums.size()==1){
            return ans;
        }
        for(int j=1;j<nums.size();j++){
            if(nums[j-1]+1 ==nums[j] && nums[j-1]<nums[j]){
                ans +=1;
            }
            else if(nums[j-1]+1 != nums[j] && nums[j-1]==nums[j]){
                ans=ans;
            }
            else{
                ans=1;
            }
            maxi=max(maxi,ans);
        }
        return maxi;
    }
};
