class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
      map<int,int>mpp;
      mpp[0]=1;
      int presum=0;
      int cnt=0;
      for(int i=0;i<nums.size();i++){
        presum+=nums[i];
        int remove=presum-k;
        cnt+=mpp[remove];
        mpp[presum]++;
      }
        return cnt;
    }
};