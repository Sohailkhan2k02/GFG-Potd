class Solution {
  public:
    int minSteps(vector<int>& arr, int start, int end) {
        // code here
        if (start == end) return 0;
        
        vector<int> dist(1000, -1);
        queue<int> q;
        
        dist[start] = 0;
        q.push(start);
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            
            for (int factor : arr) {
                int nextNode = (node * factor) % 1000;
                
                if (dist[nextNode] == -1) {
                    dist[nextNode] = dist[node] + 1;
                    if (nextNode == end) return dist[nextNode];
                    q.push(nextNode);
                }
            }
        }
        
        return -1;
    }
};
