class Solution {
public:
    int resilientSubarray(vector<int>& nums, int k) {
        int count= 0;
        int n= nums.size();
        int maxLen= 0;
            
        for(int i= 0; i< nums.size(); i++){
            int r= nums[i] %k;
            for (int j = i; j < n; j++) {
                if (nums[j] % k != r) {
                    break;
                }
                int L = j - i + 1;//count
                if (r == 0 || ((L - 1) * r) % k == 0) {
                    maxLen = max(maxLen, L);
                }
            }
        }

        
        return maxLen;


        
    }
};