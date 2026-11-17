class Solution {
public:

    int solveMem(int faces, int dice, int target, vector<vector<int>> &dp){
        
        const int MOD = 1000000007;

        //Base Case 
        if(target < 0){
            return 0;
        }
        
        if(dice == 0 && target != 0){
            return 0;
        }
        
        if(dice != 0 && target == 0){
            return 0;
        }
        
        if(dice == 0 && target == 0){
            return 1;
        }
        
        if(dp[dice][target] != -1){
            return dp[dice][target];
        }
        
        int ans= 0;
        
        //Aap jis bhi dice par khade hain, uss dice ke saare ke saare faces ko utilize karna hai 
        
        for(int i= 1; i<= faces; i++){
            ans= (ans+ solveMem(faces, dice- 1, target-i, dp))%MOD;
        }
        
        return dp[dice][target]= ans;
        
    }
    
    int solveTab(int f, int d, int t){
        
        const int MOD = 1000000007;

        vector<vector<int>> dp(d+1, vector<int>(t+1, 0));
        
        
        dp[0][0]= 1;
        
        for(int dice= 1; dice<= d; dice++){
            for(int target= 1; target<= t; target++){
                
                int ans= 0;
                
                //Aap jis bhi dice par khade hain, uss dice ke saare ke saare faces ko utilize karna hai 
                for(int i= 1; i<= f; i++){
                    
                    if(target - i >= 0)
                        ans= (ans+ dp[dice- 1][target-i])%MOD;
                }
                
                dp[dice][target]= ans;
 
            }
        }
        
        return dp[d][t];
        
    }

    int solveSpace(int f, int d, int t){

        const int MOD = 1000000007;

        vector<int> prev(t+1, 0);
        vector< int> curr(t+1, 0);
        
        prev[0]= 1;
        
        for(int dice= 1; dice<= d; dice++){
            for(int target= 1; target<= t; target++){
                
                int ans= 0;
                
                //Aap jis bhi dice par khade hain, uss dice ke saare ke saare faces ko utilize karna hai 
                
                for(int i= 1; i<= f; i++){
                    
                    if(target - i >= 0)
                        ans= (ans+ prev[target-i])%MOD;
                }
                
                curr[target]= ans;
 
            }
            prev= curr;
        }
        
        return prev[t];
        
    }



    int numRollsToTarget(int n, int k, int target) {
        
        //vector<vector<int>> dp(n+1, vector<int>(target+1, -1));
        //return solveMem(k, n, target, dp);

        //return solveTab(k, n, target);

        return solveSpace(k, n, target);

    }
};