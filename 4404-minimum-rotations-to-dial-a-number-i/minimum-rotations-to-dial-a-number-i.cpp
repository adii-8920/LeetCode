class Solution {
public:
    int minRotations(string s) {

        int a= 0;//starting me
        
        int rotations= 0;
        for(int i= 0; i< s.length(); i++){
            int b= s[i] - '0';

            int diff= abs(a - b);
            rotations+= min(diff, 10-diff);
            a= b;
        }

        return rotations;
        
    }
};