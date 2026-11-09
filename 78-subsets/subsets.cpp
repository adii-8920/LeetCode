class Solution {
    private:
    void solve(vector<int> nums, vector<int> output, int index, vector<vector<int>> &ans){//jo hum idhhar ans me changes karna chahte hain vahi main() function me return kar rahe hain that's why pass by reference so that copy na bane.

        //base case
        if(index>= nums.size()){
            ans.push_back(output);
            return;
        }

        //Exclude case-> bas index badha do
        solve(nums, output, index+1, ans);

        //Include case
        int element= nums[index];
        output.push_back(element);
        solve(nums, output, index+1, ans);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> ans;// iske andar hi sab outputs store honge
        vector<int> output;//output ka array 

        int index= 0;
        solve(nums, output, index, ans);//solve ko call karne se iss wale ans me change ho chuka hoga- pass by reference so ab vo return kar denge
        return ans;
    }
};