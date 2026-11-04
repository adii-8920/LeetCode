class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        for(int i= 0; i< arr.size()-1; i++){
            int maxRight= -1;
            for(int j= i+1; j< arr.size(); j++){
                if(arr[j] > maxRight){
                    maxRight= arr[j];
                }
            }
            arr[i]= maxRight;
        }
        arr[arr.size()-1]= -1;

        return arr;
    }
};