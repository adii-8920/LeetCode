class Solution {
public:
    vector<int> maxProductPair(vector<int>& nums, int target) {

        vector<int> ans= {-1,-1};
        int maxProd= INT_MIN;
        
        for(int i= 0; i< nums.size(); i++){
            for(int j= 0; j< nums.size(); j++){
                if(nums[i] + nums[j] == target && nums[i] > nums[j] && i!= j){

                    int currentProd= nums[i]* nums[j];
                    if(currentProd > maxProd){
                        maxProd= currentProd;
                        ans= {i,j};
                    }
                }
            }
            
        }

        return ans;
        

        
        


        


        
    }
};