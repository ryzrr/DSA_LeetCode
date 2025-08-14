class Solution {
public:
    double myPow(double x, int n) {
        double ans =1.0;
        long long  copy_n=n;
        if(copy_n<0) copy_n=-1*copy_n; 
        while(copy_n>0){
            if(copy_n%2==1){
                ans=ans*x;
                copy_n=copy_n-1;
            }
            else{
                x=x*x;
                copy_n=copy_n/2;
            }

        }
        if(n<0){
            ans=(double)(1.0)/(double)(ans);
        }
        return ans;
    }
};