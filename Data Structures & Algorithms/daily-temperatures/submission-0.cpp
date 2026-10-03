class Solution {
public:
    stack<pair<int,int>> st;
    vector<int> ans;

    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();

        for(int j = n - 1; j >= 0; j--) {

            while(!st.empty() && temperatures[j] >= st.top().first) {
                st.pop();
            }

            if(st.empty()) {
                ans.push_back(0);
            }
            else {
                int val = st.top().second - j;
                ans.push_back(val);
            }

            st.push({temperatures[j], j});
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};