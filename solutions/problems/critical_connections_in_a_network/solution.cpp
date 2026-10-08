class Solution {
public:

    void dfs(int node, int parent, int &timer, vector<int> &disc, vector<int> &low, unordered_map<int, list<int>> &adj, unordered_map<int, bool> &vis, vector<vector<int>> &ans){
                
                vis[node]= 1;
                disc[node]= low[node]= timer++;
                int child= 0;
                
                for(auto neighbour: adj[node]){
                    
                    if(neighbour == parent){
                        continue;//ignore 
                    }
                    
                    else if(!vis[neighbour]){
                        
                        dfs(neighbour, node, timer, disc, low, adj, vis, ans);//Recursive Call
                        
                        //Jab wapas aate hain recursive call se 
                        low[node]= min(low[node], low[neighbour]);
                        
                        //Check AP or not
                        if(low[neighbour] > disc[node]){
                            ans.push_back({node, neighbour});
                        }
                    }
                    
                    else{//Node Already Visited and Not Parent-> BackEdge-> Update Low
                        low[node]= min(low[node], disc[neighbour]);
                        
                    }
                }               
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
        //Create Adjacency List 
        unordered_map<int, list<int>> adj;
        
        for(int i= 0; i< connections.size(); i++){
            int u= connections[i][0];
            int v= connections[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        int timer= 0;
        int parent= -1;
        vector<int> disc(n);
        vector<int> low(n);
        unordered_map<int, bool> vis;
        vector<int> ap(n, 0);//Start hoga 0 se
        
        //Initialize
        for(int i= 0; i< n; i++){
            disc[i]= -1;
            low[i]= -1;
        }
        
        //DFS
        vector<vector<int>> ans;
            
        for(int i= 0; i< n; i++){
            if(!vis[i]){
                dfs(i, parent, timer, disc, low, adj, vis, ans);
            }
        }

        return ans;

    }

};