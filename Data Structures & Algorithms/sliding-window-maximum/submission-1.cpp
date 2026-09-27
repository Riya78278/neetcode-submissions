class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int left = 0;
        int right = 0;
        int n = nums.size();

        vector<int> ans;

        priority_queue<pair<int,int>> pq;

        while(right < n) {

            pq.push({nums[right], right});

            if(right - left + 1 == k) {

                // Remove elements outside the window
                while(pq.top().second < left) {
                    pq.pop();
                }

                ans.push_back(pq.top().first);

                left++;
            }

            right++;
        }

        return ans;
    }
};