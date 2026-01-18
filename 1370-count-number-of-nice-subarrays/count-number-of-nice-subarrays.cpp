class Solution {
public:
int atMost(vector<int>nums ,int k) {
        int l=0;
        int r=0;
        int sum=0;
        int cnt =0;
        if(k<0) return  0 ;
        while(r<nums.size()){
            sum +=nums[r];
            while(sum>k){
                sum-=nums[l];
                l++;
            }
            cnt=cnt+(r-l+1);
            r++;
        }
        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
         for(int i =0; i<nums.size();i++){
            nums[i]=nums[i]%2;
        }
         return atMost(nums,k)-atMost(nums,k-1);
    }
};