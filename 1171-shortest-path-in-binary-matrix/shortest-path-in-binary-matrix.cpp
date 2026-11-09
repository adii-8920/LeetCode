
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n= grid.size();

        if(grid[0][0] == 1 || grid[n-1][n-1] == 1){
            return -1;
        }

        // Queue me 3 cheezein rahengi: {row, col, steps}
        queue<vector<int>> q;

        q.push({0,0,1});
        grid[0][0]= 1;

        int dRow[]= {-1, 1, 0, 0, -1, -1, 1, 1};//Up, Down, Left, Right, Top-left, Top-right, Bottom-left, Bottom-right
        int dCol[]= {0, 0, -1, 1, -1, 1, -1, 1};

        //Do BFS
        while(!q.empty()){

            auto curr= q.front();
            q.pop();

            int r= curr[0];// current row
            int c= curr[1];// current col
            int steps= curr[2];// ab tak ke steps

            if(r == n-1 && c == n-1){
                return steps;
            }

            for(int i= 0; i< 8; i++){
                int newR= r + dRow[i];
                int newC= c + dCol[i];

                if(newR>= 0 && newR< n && newC>= 0 && newC<n &&grid[newR][newC] == 0){
                    grid[newR][newC]= 1;//Visited mark kar do
                    q.push({newR, newC, steps+1});//isliye daala queue me taaki hr neighbour visit ho ske
                }
            }
        }
        return -1;
    }
};