class Solution {
public:

    // DFS check kar raha hai: kya src se target tak koi rasta hai?
    bool dfs(int src, int target, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adjList){
    
    if(src == target){
        return true;
    }

    visited[src]= true;//mark visited

    //har connected node ke liye Recursive Call
    for(auto neighbour: adjList[src]){
        if(!visited[neighbour]){
            if(dfs(neighbour, target, visited, adjList)){//DFS neighbour ko pakadta hai aur rukta nahi hai—wo uske bhi neighbour, fir uske bhi aage (depth me) tab tak ghusta chala jaata hai jab tak target na mil jaye ya rasta khatam na ho jaye. Isi ko recursion kehte hain.

                return true;// aage rasta mil gaya
            }
        }
    }
    return false;

    /*
    Rasta kab milta hai: Jab recursion chalte-chalte base condition hit karta hai—yaani src == target ho jata hai (hum manzil tak pahunch gaye).

True kab aayega: Jaise hi src == target par return true; hota hai, recursion wahi true wapas piche saare calls ko pass karta hua function se bahar nikal aata hai.
*/

}

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        unordered_map<int, list<int>> adjList;

        for(int i= 0; i< edges.size(); i++){

            int u= edges[i][0];
            int v= edges[i][1];

            unordered_map<int, bool> visited;

            if(dfs(u, v, visited, adjList)){
                return {u,v};
            }
            
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        
        return {};


    }
};