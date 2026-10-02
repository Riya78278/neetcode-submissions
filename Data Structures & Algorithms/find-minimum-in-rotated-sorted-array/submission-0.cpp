class Solution {
public:
    int findMin(vector<int> &nums) {
        int low=0;
        int right=nums.size()-1;
        int ans=INT_MAX;

        while(low<=right){
            int mid=low+(right-low)/2;
            if(nums[low]<=nums[mid]){
                ans=min(ans,nums[low]);
                low=mid+1;
            }
            else{
                ans=min(ans,nums[mid]);
                right=mid-1;
            }
        }
        return ans;
    }
};
