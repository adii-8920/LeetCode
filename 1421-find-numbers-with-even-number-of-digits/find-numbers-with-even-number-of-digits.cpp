class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int numCount= 0;

        for(int i= 0; i< nums.size(); i++){
            
            int n= nums[i];
            int count= 0;

            while(n > 0){
                count++;//number of digits ka count badha diya
                n= n/10;// aakhiri digit hatata jayega
            }

            if(count % 2 == 0){
                numCount++;
            }
            
        }

        return numCount;
    }

};