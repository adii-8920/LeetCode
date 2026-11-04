class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currentSum= 0;
        int maxSum= INT_MIN;

        for(int i= 0; i< nums.size(); i++){
            currentSum+= nums[i];

            if(currentSum > maxSum){
                maxSum= currentSum;
            }

            if(currentSum < 0){//-ve number will reduce maxSum
                currentSum= 0;//reset currentSum to 0 -> which will mark the starting of a new Subarray from the next element
            }
        }
        return maxSum;
    }  
};

//Iss approach ko Kadane's Algorithm kehte h