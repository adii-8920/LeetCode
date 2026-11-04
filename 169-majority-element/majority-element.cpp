class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n= nums.size();
        return nums[n/2];// the majority element occurs more than n/2 times, and when the array is sorted, it will occupy the middle position.
    }
};