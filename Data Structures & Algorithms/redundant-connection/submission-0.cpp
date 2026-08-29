class Disjointset{
    public:
    vector<int>parent;
    vector<int>rank;
    Disjointset(int n){
        parent.resize(n+1);
        rank.resize(n+1,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }

    int finduparent(int node){
        if(node== parent[node]){
            return node;
        }
        return parent[node]=finduparent(parent[node]);
    }

    void unionbyrank(int u,int v){
        int upper_u=finduparent(u);
        int lower_v=finduparent(v);
        if(upper_u== lower_v) return;
        if(rank[upper_u]<rank[lower_v]){
            parent[upper_u]=lower_v;
        }
        else if(rank[upper_u]>rank[lower_v]){
            parent[lower_v]=upper_u;
        }
        else{
            parent[lower_v]=upper_u;
            rank[upper_u]++;
        }
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        Disjointset ds(n);
        stack<pair<int,int>>st;
        vector<int>ans;
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            if(ds.finduparent(u)==ds.finduparent(v)){
                st.push({u,v});
            }
            else{
                ds.unionbyrank(u,v);
            }
        }
        ans.push_back(st.top().first);
        ans.push_back(st.top().second);
        return ans;


    }
};
