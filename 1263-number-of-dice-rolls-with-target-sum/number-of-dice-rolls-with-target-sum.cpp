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




    int numRollsToTarget(int n, int k, int target) {
        
        vector<vector<int>> dp(n+1, vector<int>(target+1, -1));
        return solveMem(k, n, target, dp);

    }
};