class Solution {
public:
    int countRotations(string s, int k) {

        int ans= 0;
        for(int i= 0; i< s.length(); i++){
            string rotated= s.substr(i) + s.substr(0,i);
            int score= 0;
            
            for(int j= 0; j< rotated.size()-1; j++){
                if(rotated[j] == rotated[j+1]){
                    score++;
                }
            }
            if(score == k){
                ans++;
            }
        }
        return ans;
    }
};