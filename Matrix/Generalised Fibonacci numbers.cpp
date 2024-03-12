// T.C: O(logn)+O(n^3)
// S.C: O(n^2)

class Solution {
public:
    vector<vector<long long>> multiply(const vector<vector<long long>>& A, const vector<vector<long long>>& B, long long m) {
        int size = A.size();
        vector<vector<long long>> result(size, vector<long long>(size, 0));
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                for (int k = 0; k < size; ++k) {
                    result[i][j] += A[i][k] * B[k][j];
                    result[i][j] %= m;
                }
            }
        }
        return result;
    }

    long long genFibNum(long long a, long long b, long long c, long long n, long long m) {
        if (n <= 2)
            return 1LL % m;
        vector<vector<long long>> mat = {{a, b, 1}, {1, 0, 0}, {0, 0, 1}};
        vector<vector<long long>> res = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
        n -= 2;
        while (n > 0) {
            if (n & 1)
                res = multiply(res, mat, m);
            mat = multiply(mat, mat, m);
            n >>= 1;
        }
        return (res[0][0] + res[0][1] + c * res[0][2]) % m;
    }
};
