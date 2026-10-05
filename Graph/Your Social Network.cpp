class Solution {
  private:
	void dfs(int nodeA, int nodeB, int steps, vector<int>&arr,
	vector<vector<int>> &result) {
		if (nodeB - 2 >= 0) {
			dfs(nodeA, arr[nodeB - 2], steps + 1, arr, result);
		}
		result.push_back({nodeA, nodeB, steps});
	}
	public:
	vector<vector<int>> socialNetwork(vector<int>& arr) {
		// code here
		vector<vector<int>> result;
		int n = arr.size();
		for (int i = 0; i<n; ++i) {
			int nodeA = i + 2;
			int nodeB = arr[i];
			dfs(nodeA, nodeB, 1, arr, result);
		}
		return result;
	
    }
};
