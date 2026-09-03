class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;

        
        priority_queue<pair<int, int>> pq;

        for (int i = 0; i < points.size(); i++) {
            int x = points[i][0];
            int y = points[i][1];

            int distance = x * x + y * y;

            pq.push({distance, i});

            if (pq.size() > k) {
                pq.pop();
            }
        }

        while (!pq.empty()) {
            ans.push_back(points[pq.top().second]);
            pq.pop();
        }

        return ans;
    }
};