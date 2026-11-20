class Solution {
public:

    bool solve(int index, vector<int> &nums, int n, int target){
        
        //Base Case
        if(index>= n){
            return 0;
        }
        
        if(target< 0){
            return 0;
        }
        
        if(target == 0){
            return 1;
        }
        
        bool include= solve(index+1, nums, n, target- nums[index]);
        bool exclude= solve(index+1, nums, n, target);
        
        return include or exclude;
        
    }
    
    bool solveMem(int index, vector<int> &nums, int n, int target, vector<vector<int>> &dp){
        
        //Base Case
        if(index>= n){
            return 0;
        }
        
        if(target< 0){
            return 0;
        }
        
        if(target == 0){
            return 1;
        }
        
        if(dp[index][target] != -1){
            return dp[index][target];
        }
        
        bool include= solveMem(index+1, nums, n, target- nums[index], dp);
        bool exclude= solveMem(index+1, nums, n, target, dp);
        
        return dp[index][target]= include or exclude;
        
    }
    





    bool canPartition(vector<int>& nums) {
        
        int n= nums.size();
        int total= 0;
        for(int i= 0; i< n; i++){
            total+= nums[i];
        }
        
        if(total & 1){//Odd number 
            return 0;
        }
        
        int target= total/2;

        //return solve(0, arr, n, target);

        vector<vector<int>> dp(n, vector<int>(target+1, -1));

        return solveMem(0, nums, n, target, dp);



    }
};