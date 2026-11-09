class TrieNode{
    public:
        char data;
        TrieNode* children[26];
        int childCount;
        bool isTerminal;

        TrieNode(char ch){
            data= ch;
            for(int i= 0; i< 26; i++){
                children[i]= NULL;
            }
            childCount= 0;//starting me
            isTerminal= false;//starting me
        }
};

class Trie{
    public:
        TrieNode* root;

        Trie(char ch){
            root= new TrieNode(ch);
        }

        void insertUtil(TrieNode* root, string word){
            //base case
            if(word.length() == 0){
                root->isTerminal= true;
                return;
            }
            
            //Assumption: word will be in CAPS
            int index= word[0]- 'a';
            TrieNode* child;

            //Present
            if(root->children[index] != NULL){//root ke children ka index
                child= root->children[index];//aage badh jaao
            }
            else{
                //Absent
                child= new TrieNode(word[0]);//new node banao and usme character daaldo
                root->childCount++;
                root->children[index]= child;//daal do array me
            }

            //Recursion
            insertUtil(child, word.substr(1));//aage wala part pass kar diya first wale character ko chhodkar

        }

        void insertWord(string word){
            insertUtil(root, word);
        }

        void lcp(string str, string &ans){

            for(int i= 0; i< str.length(); i++){
                char ch= str[i];

                if(root->childCount == 1){
                    ans.push_back(ch);
                    //aage badh jaao
                    int index= ch - 'a';
                    root= root->children[index];
                }
                else{
                    break;
                }
                if(root->isTerminal){
                    break;
                }

            }
        }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        Trie *t= new Trie('\0');

        //insert kardo all strings into trie
        for(int i= 0; i< strs.size(); i++){

            if(strs[i] == ""){
                return "";
            }
            t->insertWord(strs[i]);
        }

        string first= strs[0];
        string ans= "";

        t->lcp(first, ans);
        return ans;
    }
};