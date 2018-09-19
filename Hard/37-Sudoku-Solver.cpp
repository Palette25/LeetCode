
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        /*
        * Initialize these arrays
        */
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j] != '.') {
                    int num = board[i][j] - '0';
                    row[i][num] = true;
                    column[j][num] = true;
                    block[i/3*3+j/3][num] = true;
                }
            }
        }
        recursive_solve(board, 0);
    }
    
    bool recursive_solve(vector<vector<char>>& board, int index){
        if(index == 81) return true;
        int row_ = index / 9, col_ = index % 9;
        if(board[row_][col_] != '.') 
            return recursive_solve(board, index+1);
        for(int num=1; num<=9; num++){
            if(!row[row_][num] && !column[col_][num] && !block[row_/3*3+col_/3][num]) {
                row[row_][num] = true;
                column[col_][num] = true;
                block[row_/3*3+col_/3][num] = true;
                // Change the cell's number
                board[row_][col_] = num + '0';
                // Return recursive result if it makes sense in next turn
                if(recursive_solve(board, index+1))
                    return true;
                else {
                    row[row_][num] = false;
                    column[col_][num] = false;
                    block[row_/3*3+col_/3][num] = false;
                    board[row_][col_] = '.';
                }
            }
        }
        return false;
    }
    
private:
    /* 
    * These two bool 2's dim array represents the special row or column or block has the number or not
    */ 
    bool row[10][10], column[10][10], block[10][10];
};