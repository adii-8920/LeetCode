class Solution {
    private:
    void solve(vector<int> nums, vector<vector<int>> &ans, int index){

        //base case
        if(index>= nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int j= index; j< nums.size(); j++){
            swap(nums[index], nums[j]);
            solve(nums, ans, index+1);//Baaki recursion sambhaal lega

            //backtrack- swap ka effect neutralise kar rahe hain.
            swap(nums[index], nums[j]);//mai original string ke andar hi changes kar raha hu isliye wapas swap karaan apadega taaki jo changes ho vo original string me ho na ki swapped string mein.
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
       vector<vector<int>> ans;
       int index= 0;
       solve(nums, ans, index);
       return ans; 
    }
};