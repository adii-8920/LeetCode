class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int, int> blockCount;//Map banaya: Key = Number, Value = Wo number kitni baar naye tukde (block) me shuru hua
        for(int i= 0; i< nums.size(); i++){
            if(i== 0 || nums[i] != nums[i-1]){//Agar pehla element hai (i == 0) -> naya block shuru hua YA current element pichle wale se alag hai (nums[i] != nums[i-1]) -> naya block shuru hua
                blockCount[nums[i]]++;// Us specific number ka block count 1 badha diya
            }
        }

        int ans= 0;
        for(auto i: blockCount){
            if(i.second == 1){//agar 1 hi block hai
                ans++;//special hai
            }
        }

        return ans;
    }
};