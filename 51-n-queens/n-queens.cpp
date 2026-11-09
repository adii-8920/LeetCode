class Solution {
public:


bool isSafe(int row, int col, vector<string> &board, int n){

	int x= row;
	int y= col;

	//Check for same row
	while(y>= 0){
		if(board[x][y] == 'Q'){
			return false;
		}
		y--;
	}
	//No need to check col as we move to next col as soon as we place a queen

	//Check diagonal

	//Upar jaane wali diagonal(top-left jaati hui)
	x= row;
	y= col;
	while(x>= 0 && y>= 0){
		if(board[x][y] == 'Q'){
			return false;
		}
		x--;
		y--;
	}

	//Neeche jaane wali diagonal(bottom-left jaati hui)
	x= row;
	y= col;
	while(x< n && y>= 0){
		if(board[x][y] == 'Q'){
			return false;
		}
		x++;
		y--;
	}

	return true;//yahaan tk pahuch gaye mtlb koi kisiko attack nahi kr rha

}


void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n){

	//base case
	if(col == n){//board bhar gaya
		ans.push_back(board);//board ko ans me daal do
		return;
	}

	//Solve 1 case, rest recursion will take care

	//Pahle column ki saari rows pe jaana hai

	for(int row= 0; row< n; row++){
		if(isSafe(row, col, board, n)){
			board[row][col]= 'Q';//queen place kar di

			//Recursive Call
			solve(col+1, board, ans, n);//next column ke liye recursive call
			
			//Backtrack
			board[row][col]= '.';
		}
	}

}



    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string (n, '.'));
        vector<vector<string>> ans;
        solve(0, board, ans, n);

        return ans;
    }
};

/*
**Haan, bilkul 100% sahi pakda hai!**

string -> Ek single row (e.g., `"..Q."`)
vector<string> -> Pura ek valid chessboard (4 rows ka group)
vector<vector<string>> ->Final `ans` (saare valid chessboards ka collection)

Kyunki LeetCode par har row khud ek `string` ban gayi, isliye poora board `vector<string>` bana aur saare boards milkar `vector<vector<string>>` ban gaye.
*/