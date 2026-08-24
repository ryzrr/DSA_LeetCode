class Solution {
public:
    bool sumGame(string nums) {
        int sumL  =0;
        int sumR =0;
        int q1 = 0;
        int  q2 =0;
        int n  =nums.size();
        for(int i =0; i<n/2;i++){
            if(nums[i]=='?') q1++;
            else sumL+= nums[i]-'0';
        }
          for(int i =n/2; i<n;i++){
            if(nums[i]=='?') q2++;
            else sumR+= nums[i]-'0';
        }


        int  total =  q1+q2;
        if(total%2 ==1)return true;

        int diff= sumL-sumR;
        int req =  9*(q2-q1)/2;

        return diff!=req;
    }
};