class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row= matrix.size();
        int col= matrix[0].size();

        int rowIndex= 0;//jahaan se start karna hai
        int colIndex= col-1;//jahaan se start karna hai

        while(rowIndex< row && colIndex>= 0){
            int element= matrix[rowIndex][colIndex];//top right corner wala element
            if(element== target){
                return 1;
            }
            if(element< target){
                rowIndex++;
            }
            else{
                colIndex--;
            }
        }
        return 0;
    }
};