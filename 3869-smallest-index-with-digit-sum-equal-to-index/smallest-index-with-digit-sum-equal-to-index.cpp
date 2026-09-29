class Solution {
public:
    int digitSum(int x){
        int sum  = 0 ;
            while(x > 0){
                int  r = x%10;
                sum+=r;
                x =x/10;
            }
            return sum ; 
    }
    int smallestIndex(vector<int>& nums) {
        int minAns = INT_MAX;
        for(int i =0 ; i< nums.size();i++){
            int digi = digitSum(nums[i]);
            if(digi == i){
                minAns  =  min(i,minAns);
            }
  
        }
        return  minAns == INT_MAX ? -1 : minAns;
    }
};