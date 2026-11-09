class Solution {
public:

    bool isSafe(int row, int col, vector<vector<char>>& board, int val){
    for(int i= 0; i< board.size(); i++){
        if((board[row][i]== val) || board[i][col] == val){//row and col check
            return false;
        }

        //Check 3X3 Matrix
        if(board[3*(row/3) + i/3][3*(col/3) + i%3] == val){//ye formula har 3X3 ke element ko represent karta hai
            return false;
        }
    }
    return true;
}

bool solve(vector<vector<char>>& board){
    int n= board[0].size();

    for(int row= 0; row< n; row++){
        for(int col= 0; col< n; col++){
            
            //cell empty
            if(board[row][col] == '.'){
                for(int val= '1'; val<= '9'; val++){
                    if(isSafe(row, col, board, val)){
                        board[row][col]= val;
                        //Recursive Call- for further solutions
                        bool furthersol= solve(board);
                        if(furthersol){
                            return true;//agar true matlab already value rakh hi gayi hogi
                        }
                        else{
                            //backtrack
                            board[row][col]= '.';
                        }
                    }     
                }
                return false;//agar 1-9 tk kuch bhi nahi solution nikla toh return false
            }
        }
    }
    return true;
}


    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};