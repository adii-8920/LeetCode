
class Solution {
public:
    int subtractProductAndSum(int n) {
        int sum= 0;
        int prod= 1;
        while(n!= 0){
            int x= n%10;
            sum= sum+ x;
            prod= prod* x;
            n/=10;
        }
        return prod-sum;
    }
};