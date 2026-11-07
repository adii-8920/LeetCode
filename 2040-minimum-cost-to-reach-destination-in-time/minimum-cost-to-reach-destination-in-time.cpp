class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int n = passingFees.size();

        unordered_map<int, list<pair<int, int>>> adj;

        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int travelTime = edges[i][2];

            adj[u].push_back({v, travelTime});
            adj[v].push_back({u, travelTime});
        }

        vector<int> minTime(n, INT_MAX);

        //{cost, time, node} — cost ke hisaab se minimum upar rahega
        priority_queue<vector<int>, vector<vector<int>> , greater<vector<int>>> pq;

        pq.push({passingFees[0], 0, 0});
        minTime[0]= 0;

        while(!pq.empty()){
            auto top= pq.top();
            pq.pop();

            int currCost= top[0];
            int currTime= top[1];
            int topNode= top[2];

            // Jaise hi destination (n - 1) mili, wahi hamara answer hai
            if(topNode == n-1){
                return currCost;
            }

            for(auto neighbour : adj[topNode]){//ka matlab hai topNode se seedhe jude huye agle shehron (neighbors) par road ke zariye jana

                int nextNode= neighbour.first;
                int roadTime= neighbour.second;

                int newTime= currTime + roadTime;
                int newCost= currCost + passingFees[nextNode];
                
                // Condition 1: Time maxTime se zyada na ho
                // Condition 2: Kya is node par pehle se KAM TIME me pahunch sake?

                if(newTime <= maxTime && newTime < minTime[nextNode]){
                    minTime[nextNode]= newTime;
                    pq.push({newCost, newTime, nextNode});
                }


            }
        }

        return -1;

    }
};

/*
Jab padosi ke andar calculate kiya tha:

C++
int newCost = currCost + passingFees[nextNode];
pq.push({newCost, newTime, nextNode});
Wahan destination ka cost calculate hokar newCost ke roop me queue me store ho gaya tha.

Agli iteration me jab wahi destination node queue se bahar nikaali (pq.pop()), toh wahi newCost pop hoke currCost variable me assign ho gaya!
*/