class Solution {
public:
    bool isValid(int row, int col, char ch, vector<vector<char>>& board){
        for(int i=0; i<9; i++){
            
            if(board[row][i] == ch) return false;   //check for row
            
            if(board[i][col] == ch) return false;   //check for column
            
            if(board[(3*(row/3))+(i/3)][(3*(col/3))+(i%3)] == ch) return false;    ///check 3X3 sub-board
        }
        return true;
    }
    
    
    bool solve(vector<vector<char>>& board){
        for(int row=0; row<9; row++){
            for(int col=0; col<9; col++){
                if(board[row][col] == '.'){ //find empty cell
                    for(char ch = '1'; ch <= '9'; ch++){
                        if(isValid(row, col, ch, board)){
                            
                            board[row][col] = ch;
                            if(solve(board) == true) return true;   //if success return true
                            else board[row][col] = '.';             //un-assign & check for next num 

                        }
                    }
                    return false;   //if no num could be assigned return false;
                }
            }
        }
        return true;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};
