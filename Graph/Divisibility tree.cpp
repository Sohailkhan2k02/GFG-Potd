//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int dfs(vector<int>adj[], int u, int prt, int &ans)
    {
        int count=0;
        for(auto v : adj[u])
        {
            if(v!=prt)
            {
                int x = dfs(adj, v, u, ans);
                if(x%2==0)
                {
                    ans++;
                }
                else
                {
                    count+=x;
                }
            }
            
        }
        return count+1;
    }
    
    int minimumEdgeRemove(int n, vector<vector<int>>edges){
        vector<int>adj[n];
        for(int i=0; i<edges.size(); i++)
        {
            adj[edges[i][1]-1].push_back(edges[i][0]-1);
            adj[edges[i][0]-1].push_back(edges[i][1]-1);
        }
        
        int ans=0;
        dfs(adj,0,-1,ans);
        return ans;
	    
	}
};
