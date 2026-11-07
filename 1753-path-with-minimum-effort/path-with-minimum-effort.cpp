#include <queue>
#include <cmath>

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        
        int rows= heights.size();
        int cols= heights[0].size();

        vector<vector<int>> dist(rows, vector<int>(cols, INT_MAX));

        // Min-heap jo store karegi: {effort, r, c}
        priority_queue<tuple<int,int,int> , vector<tuple<int,int,int>>, greater<>> pq;

        dist[0][0]= 0;
        pq.push({0,0,0});

        // 4 directions: Up, Down, Left, Right
        int dr[]= {-1, 1, 0, 0};
        int dc[]= {0, 0, -1, 1};

        while(!pq.empty()){
            auto [current_effort, r, c]= pq.top();
            pq.pop();

            if(r == rows-1 && c == cols-1){
                return current_effort;
            }
            if(current_effort > dist[r][c]){
                continue;
            }

            for(int i= 0; i< 4; i++){
                int newr= r+ dr[i];
                int newc= c+ dc[i];

                if(newr>= 0 && newr < rows && newc >=0 && newc < cols){

                    int step_jump= abs(heights[r][c] - heights[newr][newc]);// step jump nikaala

                    int new_effort= max(current_effort, step_jump);//max abs diff

                    if(new_effort < dist[newr][newc]){//minimum store kar leta hai.
                        dist[newr][newc]= new_effort;
                        pq.push({new_effort, newr, newc});
                    }

                }

            }
        }
        return 0;

        /*
        Haan, bilkul!

r, c current position hoti hai, padosi par jaate hi woh nr, nc ban jaata hai, aur un dono heights ka absolute difference hi step jump hota hai. Ekdum accurate!
*/
    }
};