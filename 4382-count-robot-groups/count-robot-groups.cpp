class Solution {
public:
    int countGroups(vector<int>& position, vector<int>& speed, int distance) {
        int n = position.size();
        if (n == 0) return 0;

        // Step 1: t = 0 par contiguous components merge karo.
        // Har segment ka representative uska rightmost robot hoga.
        vector<int> group_speeds;
        for (int i = 0; i < n; ) {
            int j = i;
            while (j + 1 < n && position[j + 1] - position[j] <= distance) {
                j++;
            }
            // Group ka rightmost robot position[j] aur speed[j] hai
            group_speeds.push_back(speed[j]);
            i = j + 1;
        }

        // Step 2: Ab right-to-left scan karo.
        // Jo sabse aage (rightmost) group hai, wo kisi se merge nahi hoga.
        // Peeche wala group agar aage wale group se tez hai (s > min_speed_to_right),
        // toh wo eventually usko catch karke merge ho jayega.
        // Agar s <= min_speed_to_right, toh wo catch nahi kar payega aur naya group banega.
        int ans = 0;
        int m = group_speeds.size();
        int min_speed = INT_MAX;

        for (int i = m - 1; i >= 0; i--) {
            if (group_speeds[i] <= min_speed) {
                ans++;
                min_speed = group_speeds[i];
            }
        }

        return ans;
    }
};