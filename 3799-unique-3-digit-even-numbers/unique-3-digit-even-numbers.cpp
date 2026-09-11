class Solution {
public:
    int totalNumbers(vector<int>& digits) {
         unordered_set<int> mpp;
         int n =digits.size();
         for(int i =0 ; i<n;i++ ){
            for(int j = 0 ;j<n;j++){
                for(int k =0 ; k<n;k++){
                    if(j==i || k==i || k==j ){
                        continue ;
                    }
                    else{
                        if(digits[i]!=0 && (digits[k]%2==0)){
                        int num = digits[i]*100 + digits[j]*10 + digits[k];
                        mpp.insert(num);
                        }
                        continue;
                    }
                }
            }
         } 

        return mpp.size(); 
    }
};