class Solution {
public:
    int firstUniqChar(string s) {
        int n= s.size();
        vector<int> v(26,0);//26 elements, all equal to 0
        int cnt= 0;
        
        for(int i= 0; i< n; i++){
            cnt= s[i]-'a';//element ko index me convert kiya jaise a->0, b->1, c->2
            v[cnt]++;//count increase kar diya and array me store kar diya
        }
        for(int i= 0; i<n; i++){
            if(v[s[i]-'a']== 1){
                return i;
            }
        }
        return -1;
    }
};