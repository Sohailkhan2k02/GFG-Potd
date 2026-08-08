// User function Template for C++

class DSU{
    vector<int>parent,rank,size;
    public:
    DSU(int n){
        parent.resize(n+1);
        rank.resize(n,0);
        size.resize(n,1);
        for(int i=0; i<=n; i++){
            parent[i]=i;
        }
    }
    int findUpr(int node){
        if(parent[node]==node) return node;
        return parent[node]=findUpr(parent[node]);
    }
    void UnionByRank(int u, int v){
        int x=findUpr(u),y=findUpr(v);
        if(x==y) return;
        if(rank[x]<rank[y]){
            parent[x]=y;
        }
        else if(rank[x]>rank[y]){
            parent[y]=x;
        }
        else{
            parent[x]=y;
            rank[y]++;
        }
    }
     void unionBySize(int u, int v) {
        int x = findUpr(u);
        int y= findUpr(v);

        if (x != y) {
            // Union by size
            if (size[x] < size[y]) {
                parent[x] = y;
                size[y] += size[x]; 
            } else {
                parent[y] = x;
                size[x] += size[y]; 
            }
        }
    }
};
class Solution {
  public:
    int Solve(int n, vector<vector<int>>& edge) {
        // code here
        int m=edge.size();
        if(m<n-1) return -1;
        DSU ds(n);
        for(auto vec:edge){
            int u=vec[0],v=vec[1];
            ds.UnionByRank(u,v);
        }
        int cnt=0;
        for(int i=0; i<n; i++){
            if(ds.findUpr(i)==i) cnt++;
        }
        return cnt-1;
    }
};
