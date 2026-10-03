#include <unordered_map>
#include <list>
#include <limits.h>

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        
        int n= points.size();

        vector<int> key(n);//nodes ko indexes se hi darshayenge-> 1st node at 1st index
        vector<bool> mst(n);//mst me node aaya ki nahi isliye bool
        vector<int> parent(n);

        for(int i= 0; i< n; i++){
            key[i]= INT_MAX;
            parent[i]= -1;
            mst[i]= false;
        }

        //Let's start the algorithm
        key[0]= 0;//source node
        parent[0]= -1;
        int totalCost= 0;

        for(int i= 0; i< n; i++){

            int mini= INT_MAX;
            int u;//u vo node hai jiska distance/weight currently sabse kam mila hai.

            //Find the min wali node
            for(int v= 0; v< n; v++){

                if(mst[v] == false && key[v] < mini){
                    u= v;//uss node ko utha liya
                    mini= key[v];//mini update kar diya
                }
            }  

            mst[u]= true;
            totalCost+= mini;

            for(int v= 0; v< n; v++){
                if(mst[v] == false ){

                    int dist= abs(points[u][0] - points[v][0]) + abs(points[u][1] - points[v][1]);

                    if(dist < key[v]){
                        key[v]= dist;
                    }

                }
            }
        }

        return totalCost;

    }            
};
/*
Iska flow dekho:Is round mein adjacent node $v$ ka cost tumne sirf note kiya (key[v] = dist).Agle round mein loop us $v$ ko hi sabse sasta maan kar u bana deta hai.Aur line 37 par totalCost += mini wahi key[v] ko total cost mein add kar deta hai!Matlab: Har adjacent node agle rounds mein u banta hai aur tab uski cost totalCost mein add ho jati hai.
*/