class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
        int count= 0;
        int i= 0;
        while(i< hours.size()){
            if(hours[i]>= target){
                count++;
            }
            i++;
        }
        return count;
    }
};