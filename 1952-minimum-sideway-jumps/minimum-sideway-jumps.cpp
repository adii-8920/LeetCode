class Solution {
public:

    //Obstacles[i]  batata hai ki ith position pe kis lane mein obstacles pade hain 

    int solve(vector<int>& obstacles, int currlane, int currpos){

        int n= obstacles.size();
        //Base case 
        if(currpos == n){
            return 0;
        }
        
        //Same lane par agli position pe koi obstacle nahi pada hona chahiye 
        if(obstacles[currpos+1] != currlane){
            return solve(obstacles, currlane, currpos+1);
        }
        else{
            //Sidewways Jump
            int ans= INT_MAX;
            for(int i= 1; i<= 3; i++){
                if(currlane != i && obstacles[currpos] != i){
                    ans= min(ans, 1+ solve(obstacles, i, currpos));
                }
            }

            return ans;  

        }

    }

    int solveMem(vector<int>& obstacles, int currlane, int currpos, vector<vector<int>> &dp){

        int n= obstacles.size() -1;
        //Base case 
        if(currpos == n){
            return 0;
        }
        if(dp[currlane][currpos] != -1){
            return dp[currlane][currpos];
        }
        
        //Same lane par agli position pe koi obstacle nahi pada hona chahiye 
        if(obstacles[currpos+1] != currlane){
            return solveMem(obstacles, currlane, currpos+1, dp);
        }
        else{
            //Sidewways Jump
            int ans= INT_MAX;
            for(int i= 1; i<= 3; i++){
                if(currlane != i && obstacles[currpos] != i){
                    ans= min(ans, 1+ solveMem(obstacles, i, currpos, dp));
                }
            }

            dp[currlane][currpos]= ans;

            return dp[currlane][currpos];  

        }

    }

    int solveTab(vector<int>& obstacles){

        int n= obstacles.size() - 1;
        vector<vector<int>> dp(4, vector<int> (obstacles.size(), 1e9));

        dp[0][n]= 0;
        dp[1][n]= 0;
        dp[2][n]= 0;
        dp[3][n]= 0;

        for(int currpos= n-1; currpos>= 0; currpos--){
            for(int currlane= 1; currlane<= 3; currlane++){

                //Same lane par agli position pe koi obstacle nahi pada hona chahiye 
                if(obstacles[currpos+1] != currlane){
                    dp[currlane][currpos]=  dp[currlane][currpos+1];
                }
                else{
                    //Sidewways Jump
                    int ans= 1e9;
                    for(int i= 1; i<= 3; i++){
                        if(currlane != i && obstacles[currpos] != i){
                            ans= min(ans, 1+ dp[i][currpos + 1]);
                        }
                    }

                    dp[currlane][currpos]= ans;//dp[lane][0] tak aane ka minimum sideways jump per lane
                }
            }
        }

        return min(dp[2][0], min(1+ dp[1][0], 1+ dp[3][0]));

    }

    int solveSpace(vector<int>& obstacles){

        int n= obstacles.size() - 1;

        vector<int> curr(4, INT_MAX);
        vector<int> next(4, INT_MAX);

        next[0]= 0;
        next[1]= 0;
        next[2]= 0;
        next[3]= 0;

        for(int currpos= n-1; currpos>= 0; currpos--){
            for(int currlane= 1; currlane<= 3; currlane++){

                //Same lane par agli position pe koi obstacle nahi pada hona chahiye 
                if(obstacles[currpos+1] != currlane){
                    curr[currlane]=  next[currlane];
                }
                else{
                    //Sidewways Jump
                    int ans= 1e9;
                    for(int i= 1; i<= 3; i++){
                        if(currlane != i && obstacles[currpos] != i){
                            ans= min(ans, 1+ next[i]);
                        }
                    }

                    curr[currlane]= ans;//dp[lane][0] tak aane ka minimum sideways jump per lane
                }
            }
            next= curr;
        }

        return min(next[2], min(1+ next[1], 1+ next[3]));

    }

    int minSideJumps(vector<int>& obstacles) {
        
        //return solve(obstacles, 2, 0);

        //vector<vector<int>> dp(4, vector<int> (obstacles.size(), -1));
        //return solveMem(obstacles, 2, 0, dp);

        //return solveTab(obstacles);

        return solveSpace(obstacles);
    }   




};