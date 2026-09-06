class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int n= nums.size();
        int ans= 0;
        
        int half= n/2;
        long long total_sum= 0;
        
        
        for(int i: nums){
            total_sum+= i;
        }

        long long first_sum= 0;
        
        //Shuru ke first half elements ka sum
        for(int i= 0; i< half; i++){
            first_sum+= nums[i];
            
        }

        //Sliding Window Approach
        for(int i= 0; i< n; i++){
            long long second_sum= total_sum - first_sum;

            if(first_sum > second_sum){
                ans++;
            }

            //Window Update
            first_sum-= nums[i];
            first_sum+= nums[(i+half) % n];//K= window size(half)
        }
        return ans;

        
    }
};