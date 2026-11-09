class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int maxLength= 0;
        
        for(int i= 0; i< sentences.size(); i++){
            int length= 1;//Har nayi sentence ke liye length ko wapas 1 hona chahiye
            for(int j= 0; j< sentences[i].size(); j++){
                if(sentences[i][j]== ' '){
                    length++;
                }
            }
            maxLength= max(maxLength, length);
        }

        return maxLength;
    }
};