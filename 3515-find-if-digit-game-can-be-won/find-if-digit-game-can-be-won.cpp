class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int sum1= 0;//sum of single digit numbers
        int sum2= 0;//sum of double digit numbers
        for(int i= 0; i< nums.size(); i++){
            if(nums[i]< 10){
                sum1+= nums[i];
            }
            else{
                sum2+= nums[i];
            }
        }
        if(sum1!= sum2){
            return true;
        }
        return false;
    }
};