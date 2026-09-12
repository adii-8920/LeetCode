class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int ans= 0;
        
        
        for(int i= 0; i< nums.size(); i++){
            int count= 0;
            vector<int> arr;
            
            for(int j= 0; j< nums.size(); j++){
                if(nums[i] == nums[j]){
                    count++;
                    arr.push_back(j);
                }
            }
            if(count == 3 && arr[0] == i && arr[1]- arr[0] == arr[2]-arr[1]){//: "Main kisi bhi number ko sirf tabhi count karunga jab main uske pehle occurrence (arr[0]) par khada hoon."
                ans++;
            }
        }
        

        return ans;
    }
};