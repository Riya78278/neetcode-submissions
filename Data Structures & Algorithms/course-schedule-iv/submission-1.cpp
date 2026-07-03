class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        int n=numCourses;
        vector<int>indegree(n,0);
        vector<vector<int>>adj(n);
        for(auto it:prerequisites){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);

            indegree[v]++;
        }

        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        unordered_map<int,unordered_set<int>>mp;
        while(!q.empty()){
            auto node=q.front();
            q.pop();

            for(auto itt:adj[node]){
                mp[itt].insert(node);

                for(auto &preq:mp[node]){
                    mp[itt].insert(preq);
                }
                indegree[itt]--;
                if(indegree[itt]==0){
                    q.push(itt);
                }
            }
        }
        int qq=queries.size();
        vector<bool>result(qq);
        for(int i=0;i<qq;i++){
            int sr=queries[i][0];
            int dest=queries[i][1];

            bool reachable =mp[dest].contains(sr);
            result[i]=reachable;

        }
        return result;
    }
};