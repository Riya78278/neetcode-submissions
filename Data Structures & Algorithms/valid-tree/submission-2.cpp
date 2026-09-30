class DisjointSet{
    public:
    vector<int>parent;
    vector<int>rank;

    DisjointSet(int n){
        parent.resize(n+1);
        rank.resize(n+1,0);

        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    int findupar(int node){
        if(node== parent[node]){
            return node;
        }
        return parent[node]=findupar(parent[node]);
    }
    void unionbyrank(int u,int v){
        int upper_u=findupar(u);
        int lower_v=findupar(v);
        if(upper_u==lower_v)return;
        else if(rank[upper_u]<rank[lower_v]){
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
    bool validTree(int n, vector<vector<int>>& edges) {
        DisjointSet ds(n);
         if(edges.size() != n-1){
            return false;
        }
        for(auto it:edges){
            int u=it[0];
            int v=it[1];

            if(ds.findupar(u)==ds.findupar(v)){
                return false;
            }
            else{
                ds.unionbyrank(u,v);
            }
        }
        
        return true ;
    }
};
