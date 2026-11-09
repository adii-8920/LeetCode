class Solution {
public:
    int sumOfMultiples(int n) {
        vector<int> v;
        int sum= 0;
        for(int i= 1; i<= n; i++){
            if((i%3== 0) || (i%5== 0) || (i%7== 0)){
                v.push_back(i);
            }
        }
        for(int i= 0; i< v.size(); i++){
            sum+= v[i];
        }
        return sum;
    }
};