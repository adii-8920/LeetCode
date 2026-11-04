class Solution {
public:

    bool valid(char ch){
         if((ch>='a' && ch<='z') || (ch>='A' && ch<= 'Z') || (ch>= '0' && ch<= '9')){
            return true;
         }
         else{
            return false;
         }
    }

    char toLowerCase(char ch){
         if((ch>='a' && ch<='z') || (ch>= '0' && ch<= '9')){
            return ch;
         }
         else{
            char temp= ch- 'A' + 'a';//lowercase me kar diya
            return temp;
         }
    }

    bool checkPalindrome(string s){
        int st= 0;
        int e= s.length()- 1;

        while(st<= e){
            if(s[st] != s[e]){
                return false;
            }
            st++;
            e--;
        }
        return true;
    }

    bool isPalindrome(string s) {
    
        string temp= "";
        //faltu characters hatado
        for(int i= 0; i< s.length(); i++){
            if(valid(s[i])){
                temp.push_back(s[i]);
            }
        }

        //Lowercase me kardo
        for(int i= 0; i< temp.length(); i++){
            temp[i]= toLowerCase(temp[i]);
        }

        //check for palindrome
        return checkPalindrome(temp);
    }
};