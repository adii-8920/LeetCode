class Solution {
public:
    int compress(vector<char>& chars) {
        int i= 0;
        int ansIndex= 0;
        int n= chars.size();
        while(i< n){
            int j= i+1;
            while(j<n && chars[i]== chars[j]){
                j++;
            }
            //yahaan kab aaoge??
            //ya toh vector poora traverse kar diya
            //ya toh new/different character encounter kiya

            //old character store kar lo
            chars[ansIndex]= chars[i];
            ansIndex++;

            //ab count store karlo
            int count= j-i;

            if(count >1){
                //converting counting into single digit and saving in answer
                string cnt= to_string(count);
                for(char ch: cnt){
                    chars[ansIndex]= ch;
                    ansIndex++;
                }
            }
            //moving to new/Different character
            i=j;
        }
        return ansIndex;
    }
};