class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int arrSum= 0;
        int sum= 0;
        for(int i= 0; i< nums.size(); i++){
            arrSum+= nums[i];

            int temp= nums[i];
            while(temp!= 0){
                int x= temp%10;
                sum+= x;
                temp/=10;
            }
        }
        if((arrSum- sum) > 0){
            return arrSum- sum;
        }
        else{
            return sum- arrSum;
        }
    }
};