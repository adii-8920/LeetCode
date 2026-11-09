class Solution {
public:

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        //Using Kahn's Algorithm- always applicable for DAG
        
        //Create Adjacency List
        unordered_map<int, list<int>> adj;

        for(int i= 0; i< prerequisites.size(); i++){

            int u= prerequisites[i][0];
            int v= prerequisites[i][1];

            adj[v].push_back(u);

        }

        //Find all indegrees
        int v= numCourses;
        vector<int> indegree(v);

        for(auto i: adj){
            for(auto j: i.second){
                indegree[j]++;
            }
        }

        //0 indegree walo ko push kardo queue mein
        
        queue<int> q;
        for(int i= 0; i< v; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        //do bfs
        vector<int> ans;
        while(!q.empty()){
            int frontNode= q.front();
            q.pop();

            //ans store
            ans.push_back(frontNode);


            for(auto neighbour: adj[frontNode]){
                indegree[neighbour]--;

                if(indegree[neighbour] == 0){//Haan, bilkul sahi pakde ho!
    //Yeh un nodes ke liye hai jinki indegree shuru me 0 nahi thi, lekin current node ke process hone ke baad unki indegree ghatkar (-- hokar) ab 0 ban chuki hai.
    //Indegree 0 hone ka matlab hai uske saare prerequisites/dependencies complete ho gaye, toh ab woh queue me jaane ke liye ready hai.
                    q.push(neighbour);
                }

            }
        }

        if(ans.size() == numCourses){
            return ans;
        }
        else{
            return {};
        }
    }   
};