class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans= 0;

        for(auto x: nums){
            ans= ans^x;
        }

        return ans;

    }
};
/*
a^a^a......... (even times)=0 and a^a^a........(odd times)=a
*/