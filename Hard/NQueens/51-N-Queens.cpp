class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        size = n;
        for(int i=0; i<n; i++){
            vector<string> temp;
            vector<vector<bool>> enablePos;
            // Initialize the strings in each vector
            for(int j=0; j<n; j++){
                string ttmp(n, '.');
                vector<bool> bmp(n, true);
                temp.push_back(ttmp);
                enablePos.push_back(bmp);
            }
            // Recursive solving the possible positions
            generateSolution(temp, enablePos, 0, i);
        }
        return result;
    }
    
    void generateSolution(vector<string> temp, vector<vector<bool>> enablePos, int x, int y){
        temp[x][y] = 'Q';
        cout << "Yep" << x << y << endl;
        for(int i=0; i<size; i++){
            enablePos[x][i] = false;  // Disable the row
            enablePos[i][y] = false;  // Disbale the column
        }
        // Left diagonal
        for(int i=y-1; i>=0&&x+y-i<size; i--)
            enablePos[x+y-i][i] = false;
        // Right diagonal
        for(int i=y+1; i<size&&x+i-y<size; i++)
            enablePos[x+i-y][i] = false;
        // Next step decision
        int target_row = x + 1;
        vector<int> enableIndex;
        if(target_row < size){
            for(int i=0; i<size; i++){
                if(enablePos[target_row][i] == true)
                    enableIndex.push_back(i);
            }
            for(int i=0; i<enableIndex.size(); i++)
                generateSolution(temp, enablePos, target_row, enableIndex[i]);
        }else {
            result.push_back(temp);
            return;
        }
    }
    
 private:
    vector<vector<string>> result;
    int size;
};