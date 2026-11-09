class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
    for(int i= 0; i< s.size(); i++){

        char ch= s[i];

        //if opening bracket, stack mein push
        //if closing bracket, stackTop check and pop

        if((ch == '(') || (ch == '{') || (ch == '[')){
            st.push(ch);
        }
        else{

            ///for closing bracket
            if(!st.empty()){
                if((ch == ')' && st.top()== '(') || (ch == '}' && st.top()== '{') || (ch == ']' && st.top()== '[')){
                    st.pop();
                }
                else{
                    st.push(ch);
                }
            }
            else{
                return false;
            }
        }
    }
    if(st.empty()){
        return true;
    }
    else{
        return false;
    }
    }
};