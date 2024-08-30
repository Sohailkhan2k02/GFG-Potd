//T.C : O(n!)
//S.C : O(n*n)
class Solution{
public:
    void f(int col, vector<int> &board, int delrow[], int delcol[], vector<vector<int>> &res, vector<int> &rows, vector<int> &upperDiag, vector<int> &lowerDiag, int n) {
        if (col == n) {
            res.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++) {
            if (rows[row] == 0 && lowerDiag[row + col] == 0 && upperDiag[n - 1 + col - row] == 0) {
                board[col] = row + 1;
                rows[row] = 1;
                lowerDiag[row + col] = 1;
                upperDiag[n - 1 + col - row] = 1;

                f(col + 1, board, delrow, delcol, res, rows, upperDiag, lowerDiag, n);

                rows[row] = 0;
                lowerDiag[row + col] = 0;
                upperDiag[n - 1 + col - row] = 0;
            }
        }
    }

    vector<vector<int>> nQueen(int n) {
        vector<vector<int>> res;
        vector<int> board(n, 0);

        vector<int> rows(n, 0), upperDiag(2 * n - 1, 0), lowerDiag(2 * n - 1, 0);

        int delrow[] = {0, 1, -1, 1, -1, 0};
        int delcol[] = {1, 0, 1, -1, -1, 0};

        f(0, board, delrow, delcol, res, rows, upperDiag, lowerDiag, n);
        return res;
    }
};
