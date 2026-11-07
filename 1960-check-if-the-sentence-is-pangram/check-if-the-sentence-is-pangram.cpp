class Solution {
public:
    bool checkIfPangram(string sentence) {
        int arr[26]= {0};

        for(int i= 0; i<sentence.length(); i++){
            char ch= sentence[i];

            int index= ch-'a';
            arr[index]= 1;
        }
        for(int i= 0; i<26; i++){
            if(arr[i]== 0){
                return false;
            }
        }
        return true;
    }
};