class Solution {
public:
    int smallestNumber(int n, int t) {
       int ans  = n;
       while(true){
        int x = ans;
        int prod = 1;
        while(x>0){
            int digit =  x%10;
            prod *= digit;
            x/=10;
        }
        if(prod % t == 0) return ans;
        ans++;
       }
    }
};