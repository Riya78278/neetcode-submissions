class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        for(int i = 0; i < prerequisites.size(); i++){
           int u = prerequisites[i][0];
           int v = prerequisites[i][1];
           adj[v].push_back(u);
        }
        vector<int>indegree(numCourses,0);
        for(int i=0;i<numCourses;i++){
            for (auto it:adj[i]){
                indegree[it]++;
            }
        }

        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        vector<int>toposort;
        while(!q.empty()){
            int node=q.front();
            q.pop();

            toposort.push_back(node);
            for(auto itt:adj[node]){
                indegree[itt]--;
                if(indegree[itt]==0){
                    q.push(itt);
                }
            }
        }

        if(toposort.size()==numCourses){
            return toposort;
        }
        return {};
    }
};
