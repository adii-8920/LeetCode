class Solution {
public:
    int solveMem(vector<vector<char>>& matrix, int i, int j, int &maxi, vector<vector<int> > &dp){
        
        //base case
        if(i >= matrix.size() || j>= matrix[0].size()){
            return 0;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        int right= solveMem(matrix, i, j+1, maxi, dp);
        int diagonal= solveMem(matrix, i+1, j+1, maxi, dp);
        int down= solveMem(matrix, i+1, j, maxi, dp);
        
        if(matrix[i][j] == '1'){
            
            dp[i][j]= 1+ min(right, min(diagonal, down));
            
            maxi= max(maxi, dp[i][j]);//Update Maxi
            
            return dp[i][j];//Return Local square size for further recursive calls
            
        }
        else{
            return dp[i][j]= 0;
        }
            
    }

    int solveTab(vector<vector<char>>& matrix, int &maxi){
        
        int row = matrix.size();
        int col= matrix[0].size();
        
        vector<vector<int> > dp(row + 1, vector<int> (col + 1, 0));
        
        for(int i= row - 1; i>= 0; i--){
            for(int j= col - 1; j>= 0; j--){
                
                int right= dp[i][j+1];
                int diagonal= dp[i+1][j+1];
                int down= dp[i+1][j];
                
                if(matrix[i][j] == '1'){
                    
                    dp[i][j]= 1+ min(right, min(diagonal, down));
                    
                    maxi= max(maxi, dp[i][j]);//Update Maxi
                    
                }
                else{
                    dp[i][j]= 0;
                }
                
            }
        }
        
        return dp[0][0];
        
    }

    int solveSpace(vector<vector<char>>& matrix, int &maxi){
        
        int row = matrix.size();
        int col= matrix[0].size();
        
        vector<int> curr(col +1, 0);
        vector<int> next(col +1, 0);
        
        for(int i= row - 1; i>= 0; i--){
            for(int j= col - 1; j>= 0; j--){
                
                int right= curr[j+1];
                int diagonal= next[j+1];
                int down= next[j];
                
                if(matrix[i][j] == '1'){
                    
                    curr[j]= 1+ min(right, min(diagonal, down));
                    
                    maxi= max(maxi, curr[j]);//Update Maxi
                    
                }
                else{
                    curr[j]= 0;
                }
                
            }
            next= curr;
        }
        
        return next[0];
             
    }


    int maximalSquare(vector<vector<char>>& matrix) {
/*        
        int n= matrix.size();
        int m= matrix[0].size();
        
        int maxi= 0;
        vector<vector<int> > dp(n, vector<int> (m,-1));
        solveMem(matrix, 0, 0, maxi, dp);
        
        return maxi * maxi;
*/

/*
        int maxi= 0;
        solveTab(matrix, maxi);
        
        return maxi*maxi; 
*/
        int maxi= 0;
        solveSpace(matrix, maxi);
        return maxi* maxi;               
    }
};