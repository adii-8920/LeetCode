class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row= matrix.size();
        int col= matrix[0].size();

        int start= 0;
        int end= row*col -1;
        int mid= start+(end- start)/2;

        while(start<= end){
            int element= matrix[mid/col][mid%col];//taking out  element at mid index out of 2d array by finding its row and columns using mid/col and mid%col

            if(element== target){
                return 1;
            }
            else if(element< target){
            start= mid+ 1;
            }
            else{
                end= mid- 1;
            }
            mid= start+(end- start)/2;
        }
        return 0;
    }
};