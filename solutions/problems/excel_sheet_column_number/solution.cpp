class Solution {
public:
    int titleToNumber(string columnTitle) {
        
        int ans= 0;
        for(char ch: columnTitle){
            
            int val= ch-'A'+1;//number me convert kiya h starting from 1
            ans= ans*26 + val;
        }

        return ans;
    }
};