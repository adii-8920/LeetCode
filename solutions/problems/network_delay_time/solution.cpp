#include <unordered_map>
#include <list>
#include <set>
#include <climits>

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

    //Create Adjacency List
    unordered_map<int , list<pair<int, int>>> adj;

    for(int i= 0; i< times.size(); i++){

        int u= times[i][0];
        int v= times[i][1];
        int w= times[i][2];

        adj[u].push_back(make_pair(v,w));
        
    }

    vector<int> dist(n+1, INT_MAX);

    set<pair<int, int>> st;//distance, node

    //initialise distance and set with source node
    dist[k]= 0;
    st.insert(make_pair(0, k));//distance, node

    /*
    auto top = *(st.begin()); se top kaise aata hai?

set elements ko hamesha increasing (ascending) order me sort karke rakhta hai.

st.begin() sabse pehle (sabse chhote distance wale) element ka iterator (pointer) deta hai.

Star * us pointer ki actual value nikaalta hai.

Kyunki Dijkstra me hume hamesha minimum distance wala node sabse pehle chahiye hota hai, isliye set ka pehla element hi hamara sabse chhota aur best candidate (top) hota hai.
*/


    while(!st.empty()){

        //fetch top record
        auto top= *(st.begin());
        
        int nodeDistance= top.first;
        int topNode= top.second;

        //remove top record now
        st.erase(st.begin());

        //traverse on neighbours
        for(auto neighbour : adj[topNode]){
            if(nodeDistance + neighbour.second < dist[neighbour.first]){

                //check karo ki already entry toh nhi padi hui hai
                auto record= st.find(make_pair(dist[neighbour.first], neighbour.first));

                if(record!= st.end()){//record found
                    st.erase(record);
                }
                /*
                Set me humne pair store kiya hai: {distance, node}. Set me kisi cheez ko dhoondhne ya erase karne ke liye exact pair pata hona zaroori hai.

dist[neighbour.first] koi random value nahi hai; yeh wahi purana best distance hai jo humne pichli baar is node ke liye set me daala tha.

Example: Maan lo pehle node 5 tak pahunchne ka distance 10 mila tha, toh set me {10, 5} daala tha aur dist[5] = 10 save kiya tha.

Ab naya rasta mila jiska total distance 7 hai.

Set se purana bekaar entry {10, 5} hatana padega taaki duplicate na bache.

Hum set se kahenge: "bhai, purana record {dist[5], 5} (yaani {10, 5}) dhoondh ke mita de, taaki mai naya {7, 5} daal sakun."

Isliye dist[neighbour.first] fix nahi hai, balki current saved record ki exact purani value hai jisse set us pair ko pehchaan kar delete kar sake
*/

                //distance update
                dist[neighbour.first]= nodeDistance + neighbour.second;

                //push record in set
                st.insert(make_pair(dist[neighbour.first], neighbour.first));
            }
        }
    }

    int ans= 0;
    for(int i= 1; i<=n; i++){
        if(dist[i]== INT_MAX){
            return -1;
        }
        ans= max(ans,dist[i]);
    }
    /*
    Kyunki shuruat me humne har node ka distance INT_MAX (infinity) set kiya tha.Agar algorithm khatam hone ke baad bhi kisi node i ka distance INT_MAX hi bacha reh gaya, iska seedha matlab hai ki source $k$ se us node i tak pahunchne ka koi rasta hi nahi tha.Kyunki signal sabhi $n$ nodes tak pahunch hi nahi paya, isliye question ke rule ke mutabiq turant -1 return kar diya.
    */

    return ans;



    }
};