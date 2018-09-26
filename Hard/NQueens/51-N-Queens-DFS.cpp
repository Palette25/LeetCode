class Solution {
public:
    void dfs(vector<int>& board, int start, int n) {
        if (start == n) addToResult(board, n);
        for (int i = start; i < n; ++i) {
            swap(board[start], board[i]);
            if (checkValid(board, start, n))
                dfs(board, start+1, n);
            swap(board[start], board[i]);
        }
    }
    // check the rows before the input row number for diagonal and anti-diagonal
    bool checkValid(vector<int>& board, int row, int n) {
        for (int i = -1; row+i>=0; --i) {
            if (board[row+i] == board[row]+i ||
               board[row+i] == board[row]-i) return false;
        }
        return true;
    }
    void addToResult(vector<int>& board, int n) {
        vector<string> QD(n,string(n,'.'));
        for (int i = 0; i < n; ++i) {
            QD[i][board[i]] = 'Q';
        }
        res.push_back(move(QD));
    }
    vector<vector<string>> solveNQueens(int n) {
        // sparse matrix: board[i] denotes the column number taken for the row
        vector<int> board;
        // initialize all queens on the diagonal (without sharing rows and columns)
        for (int i = 0; i < n; ++i)
            board.push_back(i);
        dfs(board, 0, n);
        return res;
    }

private:
	vector<vector<string>> res;
};