class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> ans;
        for(int i= 0; i< operations.size(); i++){
            if(operations[i] != "C" && operations[i] != "D" && operations[i] != "+"){
                int x= stoi(operations[i]);
                ans.push_back(x);
            }
            else if(operations[i] == "+"){
                int k= ans[ans.size()-1]+ ans[ans.size()-2];
                ans.push_back(k);
                }
            else if(operations[i] == "D"){
                ans.push_back(2*ans[ans.size()-1]);
                }
            else if(operations[i] == "C"){
                ans.pop_back();
            }
        }
        int sum= 0;
        for(int i= 0; i< ans.size(); i++){
            sum+= ans[i];
        }
        return sum;
    }
};