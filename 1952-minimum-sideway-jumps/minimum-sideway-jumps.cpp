class Solution {
public:

    //Obstacles[i]  batata hai ki ith position pe kis lane mein obstacles pade hain 


    int solve(vector<int>& obstacles, int currlane, int currpos){

        int n= obstacles.size() -1 ;
        //Base Case
        if(currpos == n){
            return 0;
        }

        //Same lane par agli position pe koi obstacle nahi pada hona chahiye    
        if(obstacles[currpos + 1] != currlane){
            return solve(obstacles, currlane, currpos+1);
        }
        else{
            //Sideways Jump

            int ans= INT_MAX;
            for(int i= 1; i<= 3; i++){
                if(currlane != i && obstacles[currpos] != i){//same lane pe na ho and jidhar jump krna h udhar obstacle na ho
                    ans= min(ans, 1 + solve(obstacles, i, currpos));
                }
            }

            return ans;

        }
    }

    int solveMem(vector<int>& obstacles, int currlane, int currpos, vector<vector<int>> &dp){

        int n= obstacles.size() -1 ;
        //Base Case
        if(currpos == n){
            return 0;
        }

        if(dp[currlane][currpos] != -1){
            return dp[currlane][currpos];
        }

        //Same lane par agli position pe koi obstacle nahi pada hona chahiye    
        if(obstacles[currpos + 1] != currlane){
            return solveMem(obstacles, currlane, currpos+1, dp);
        }
        else{
            //Sideways Jump

            int ans= INT_MAX;
            for(int i= 1; i<= 3; i++){
                if(currlane != i && obstacles[currpos] != i){//same lane pe na ho and jidhar jump krna h udhar obstacle na ho
                    ans= min(ans, 1 + solveMem(obstacles, i, currpos, dp));
                }
            }
            dp[currlane][currpos]= ans;

            return dp[currlane][currpos];
        
        }

    }





    int minSideJumps(vector<int>& obstacles) {
        

        //return solve(obstacles, 2, 0);
        vector<vector<int>> dp(4, vector<int> (obstacles.size(), -1));

        return solveMem(obstacles, 2, 0, dp);




    }   
};