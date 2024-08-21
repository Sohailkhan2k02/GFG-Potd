//T.C : O O(N * |S| + K)
//S.C: O(K)
class Solution{
  vector<int> toposort(vector<int> adj[] , int K){
        int indegree[K]={0};
        for(int i=0;i<K;i++){
            for(auto it : adj[i]){
                indegree[it]++;
            }
        }
        queue<int> q;
        for(int i=0;i<K;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int> topological;
        
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            topological.push_back(node);
            
            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        return topological;
    }
    public:
    string findOrder(string dict[], int N, int K) {
        
        vector<int> adj[K];
        for(int i=0;i<N-1;i++){
         string s1=dict[i];
         string s2=dict[i+1];
            
        int len=min(s1.length(),s2.length());
        for(int pt=0;pt<len;pt++){
                if(s1[pt]!=s2[pt]){
                adj[s1[pt]-'a'].push_back(s2[pt]-'a');
                break;
                }
            }
        }
        
        vector<int> ans=toposort(adj,K);
        string st="";
        for(auto it : ans){
            st+=char(it+'a');
        }
        return st;
        
    }
};
