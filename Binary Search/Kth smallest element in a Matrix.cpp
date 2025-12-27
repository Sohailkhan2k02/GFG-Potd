class Solution {
  public:
    bool check(int num, vector<vector<int>> &mat, int k)
    {
        int cnt = 0, n = mat.size(), m = mat[0].size();
        int i = 0, j = m - 1;
        while (i < n && j >= 0)
        {
            if (mat[i][j] > num)
                j--;
            else
                cnt += (j + 1), i++;
        }
        return (cnt >= k);
    }
    int kthSmallest(vector<vector<int>> &mat, int k)
    {
        int n = mat.size() , m = mat[0].size();
        int start = mat[0][0], end = mat[n - 1][m - 1], ans = end;
        while (start <= end)
        {
            int mid = (start + end) / 2;
            if (check(mid, mat, k))
                ans = mid, end = mid - 1;
            else
                start = mid + 1;
        }
        return ans;
    }
};
