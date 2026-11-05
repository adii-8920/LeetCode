class Solution {
public:

    int solveMem(int n, vector<int> &days, vector<int> &costs, int index, vector<int> &dp){

        //base case
        if(index >= n){
            return 0;
        }

        if(dp[index] != -1){
            return dp[index];
        }

        int option1= costs[0] + solveMem(n, days, costs, index + 1, dp);

        int i;

        for(i= index; i< n && days[i] < days[index] + 7; i++);//index badhane ke liye

        int option2= costs[1] + solveMem(n, days, costs, i, dp);


        for(i= index; i< n && days[i] < days[index] + 30; i++);

        int option3= costs[2] + solveMem(n, days, costs, i, dp);

        dp[index]= min(option1, min(option2, option3));

        return dp[index];

}

int solveTab(int n, vector<int> &days, vector<int> &costs){

        vector<int> dp(n+1 , INT_MAX);

        dp[n] = 0;

        for(int k= n-1; k>= 0; k--){

            int option1= costs[0] + dp[k + 1];

            int i;

            for(i= k; i< n && days[i] < days[k] + 7; i++);//index badhane ke liye

            int option2= costs[1] + dp[i];


            for(i= k; i< n && days[i] < days[k] + 30; i++);

            int option3= costs[2] + dp[i];

            dp[k]= min(option1, min(option2, option3));


    }

    return dp[0];

}


    int mincostTickets(vector<int>& days, vector<int>& costs) {

        //int n= days.size();
        //vector<int> dp(n+1 , -1);
        //return solveMem(n, days, costs, 0, dp);

        //return solveTab(n, days, costs);


    //Via Space Optimization
    int ans= 0;
    queue<pair<int, int>> week;
    queue<pair<int, int>> month;

    for(int day: days){

        //Step 1: remove expired days
        while(!month.empty() && month.front().first + 30 <= day){
            month.pop();
        }
        while(!week.empty() && week.front().first + 7 <= day){
            week.pop();
        }

        //Step- 2: add cost for current day-> push kya kar raha hai: Yeh record kar raha hai ki "agar hum current day par naya 7-day ya 30-day pass khareed lete, toh aaj tak ka total kharcha kitna banta (ans + pass ki cost), jo agle 7 ya 30 dinon ke travel ko cover karega."
        week.push(make_pair(day, ans + costs[1]));
        month.push(make_pair(day, ans + costs[2]));

        //Step- 3: ans update 
        ans= min(ans + costs[0] , min(week.front().second, month.front().second));

    }
    return ans;


    }
};