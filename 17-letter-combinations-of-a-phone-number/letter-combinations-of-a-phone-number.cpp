class Solution {
    private:
    void solve(string digits, string output, int index, vector<string> &ans, string mapping[]){

        //base case
        if(index>= digits.length()){
            ans.push_back(output);
            return;
        }

        int number= digits[index]- '0';// uss char element ko corresponding int me convert kar diya

        string value= mapping[number];//number ke corresponding mapping
        for(int i= 0; i< value.length(); i++){
            output.push_back(value[i]);
            solve(digits, output, index+1, ans, mapping);
            output.pop_back();//hatana bhi padega o/p array se element taaki next alphabet ke liye chal paaye- jaise 'a' ke liye chala toh uske saare case ho gaye- fir ab 'b' ke cases chalenge isliye hataa rahe hain.- (backtracking)
        }

    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.length()== 0){
            return ans;
        }
        string output= "";
        int index= 0;
        string mapping[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(digits, output, index, ans, mapping);
        return ans;
    }
};