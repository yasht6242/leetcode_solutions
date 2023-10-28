class Solution {
public:
    int totalNQueens(int n) {
        int count = 0;
        vector<bool> columns(n, false);
        vector<bool> diagonals1(2 * n - 1, false);
        vector<bool> diagonals2(2 * n - 1, false);
        solveNQueens(n, 0, count, columns, diagonals1, diagonals2);
        return count;
    }
private:
    void solveNQueens(int n, int row, int& count, vector<bool>& columns, vector<bool>& diagonals1, vector<bool>& diagonals2) {
        if (row == n) {
            count++;
            return;
        }

        for (int col = 0; col < n; ++col) {
            if (!columns[col] && !diagonals1[row + col] && !diagonals2[row - col + n - 1]) {
                columns[col] = true;
                diagonals1[row + col] = true;
                diagonals2[row - col + n - 1] = true;

                solveNQueens(n, row + 1, count, columns, diagonals1, diagonals2);

                columns[col] = false;
                diagonals1[row + col] = false;
                diagonals2[row - col + n - 1] = false;
            }
        }
    }
};