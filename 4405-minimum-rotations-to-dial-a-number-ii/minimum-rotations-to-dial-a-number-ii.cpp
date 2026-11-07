class Solution {
    
int getCost(char a, char b){
    int diff= abs((a - '0') - abs(b - '0'));
    return min(diff, 10 - diff);
}    
public:
    int minRotations(int n, string s) {

    int baseCost= getCost('0', s[0]);
        for(int i= 1; i< n; i++){
            baseCost += getCost(s[i-1] , s[i]);
        }
        int ans= baseCost;

        for(int k= 0; k< n; k++){
            int currentCost= baseCost;

            if(k == 0){
                currentCost= baseCost - getCost('0', s[0]) + getCost('0', s[n-1]);
            }
            else{
                currentCost= baseCost - getCost(s[k-1], s[k]) + getCost(s[k-1], s[n-1]);
            }

            ans= min(ans, currentCost);
        }

        return ans;






        
        
        
        


        
    }
};