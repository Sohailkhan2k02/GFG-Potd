class Solution {
  public:
    using int64 = long long;
    static constexpr int MAXN = 10;

    int countSpanTree(int n, vector<vector<int>>& edges) {
        if (n == 1)
            return 1;

        // Cofactor matrix directly constructed
        int64 mat[MAXN][MAXN] = {};

        // Build Laplacian cofactor
        for (const auto& e : edges) {
            const int u = e[0];
            const int v = e[1];

            if (u < n - 1)
                ++mat[u][u];

            if (v < n - 1)
                ++mat[v][v];

            if (u < n - 1 && v < n - 1) {
                --mat[u][v];
                --mat[v][u];
            }
        }

        return static_cast<int>(bareiss(mat, n - 1));
    }

private:

    int64 bareiss(int64 a[MAXN][MAXN], int sz) {
        int64 denom = 1;
        int sign = 1;

        for (int k = 0; k < sz - 1; ++k) {
            // Pivot search
            int pivot = k;

            while (pivot < sz && a[pivot][k] == 0)
                ++pivot;
            if (pivot == sz)
                return 0;

            // Row swap
            if (pivot != k) {
                for (int j = 0; j < sz; ++j)
                    std::swap(a[k][j], a[pivot][j]);
                sign = -sign;
            }

            const int64 pivotVal = a[k][k];
            // Bareiss elimination
            for (int i = k + 1; i < sz; ++i) {
                for (int j = k + 1; j < sz; ++j) {
                    a[i][j] = (a[i][j] * pivotVal - a[i][k] * a[k][j]) / denom;
                }
            }

            denom = pivotVal;
        }

        return sign * a[sz - 1][sz - 1];
    }
};
