class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string ans= s;//Create a new string ans of the same size as s.
        for(int i= 0; i< s.size(); i++){
            ans[indices[i]]= s[i];
        }
        return ans;
    }
};