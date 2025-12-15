class Solution {
  public:
    int cntWays(vector<int>& arr) {
        // code here
        int n = arr.size();
        int x = 0, y = 0;
        for (int i = 0; i < n; i++)
            if (i & 1)
                y += arr[i];
            else
                x += arr[i];
        int a = 0, b = 0, cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (i & 1)
            {
                y -= arr[i];
                cnt += (a + y == b + x);
                b += arr[i];
            }
            else
            {
                x -= arr[i];
                cnt += (a + y == b + x);
                a += arr[i];
            }
        }
        return cnt;
    }
};
