class Solution {

    private:
	pair<int, int> bfs(int start, vector<vector<int>> &adjList) {
		int V = adjList.size();
		int furthestNode = start;
		int furthestDist = 0;
		
		vector<int>dist(V, -1);
		queue<int>q;
		q.push(start);
		dist[start - 1] = 0;
		
		while (!q.empty()) {
			int node = q.front(); q.pop();
			for (int adjNode:adjList[node - 1]) {
				if (dist[adjNode - 1] == -1) {
					dist[adjNode - 1] = dist[node - 1]+1;
					q.push(adjNode);
					if (dist[adjNode - 1]>furthestDist) {
						furthestNode = adjNode;
						furthestDist = dist[adjNode - 1];
					}
				}
			}
		}
		return {furthestDist, furthestNode};
	}
	public:
	int partyHouse(vector<vector<int>> &adj) {
		// code here
		int furthestNode = bfs(1, adj).second;
		int diameter = bfs(furthestNode, adj).first;
		return (diameter + 1)/2;
	
    }
};
