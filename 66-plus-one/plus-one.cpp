class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n= digits.size();
        for(int i= n-1; i>= 0; i--){
            if(digits[i] < 9 ){
                digits[i]++;
                return digits;
            }
            else{
                digits[i] = 0; 
            }
        }
        digits.insert(digits.begin(), 1);
                //Loop mein aakhiri digit 0 ban gayi, fir loop i ko piche le jaakar agle digit ko dekhta hai. Agar saare numbers 9 the, toh pura array [0, 0] ban kar loop se bahar aa jayega. Toh loop ke theek bahar aapko array ke shuruat mein 1 insert karna padega:  
         
        return digits;
    }
};