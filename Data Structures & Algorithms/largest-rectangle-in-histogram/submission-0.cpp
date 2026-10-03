class Solution {
public:
    void func1(vector<int>& heights, vector<int>& leftsmall) {
        stack<int> st;

        for(int i = 0; i < heights.size(); i++) {
            while(!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            if(st.empty()) {
                leftsmall.push_back(-1);
            }
            else {
                leftsmall.push_back(st.top());
            }

            st.push(i);
        }
    }

    void func2(vector<int>& heights, vector<int>& rightsmall) {
        stack<int> st;

        for(int i = heights.size() - 1; i >= 0; i--) {
            while(!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            if(st.empty()) {
                rightsmall.push_back(heights.size());
            }
            else {
                rightsmall.push_back(st.top());
            }

            st.push(i);
        }

        reverse(rightsmall.begin(), rightsmall.end());
    }

public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> leftsmall;
        vector<int> rightsmall;

        func1(heights, leftsmall);
        func2(heights, rightsmall);

        int maxi = 0;

        for(int i = 0; i < heights.size(); i++) {
            int width = rightsmall[i] - leftsmall[i] - 1;
            int area = heights[i] * width;

            maxi = max(maxi, area);
        }

        return maxi;
    }
};