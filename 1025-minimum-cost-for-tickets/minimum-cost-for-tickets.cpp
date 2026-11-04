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

        int n= days.size();
        //vector<int> dp(n+1 , -1);
        //return solveMem(n, days, costs, 0, dp);

        return solveTab(n, days, costs);
    }
};