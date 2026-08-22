class Solution {
public:
    bool checkDivisibility(int n) {
       int  sum = 0;
       int prod =1;
       int m = n;
       while(n>0){
        sum +=n%10;
        prod *= n%10;
        n/=10;
       } 
       if(m%(sum+prod)==0) return true;
       return false;
    }
};