class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int ans= 0;
        unordered_map<int, vector<int>> map;
        for(int i= 0; i< nums.size(); i++){
            map[nums[i]].push_back(i);//Yeh har number ke saamne ek list bana deta hai ki woh number kis-kis index par baitha hua hai.
        }

        for(auto pair: map){
            auto indices= pair.second;

            if(indices.size() < 3){
                continue;
            }

            int diff= indices[1] - indices[0];

            bool isValid= true;

            for(int k= 2; k< indices.size(); k++){
                if(indices[k] - indices[k-1] != diff){
                    isValid= false;
                    break;//no need to check further.
                }
            }
            if(isValid){
                ans++;
            }
        }
        return ans;        
    }
};