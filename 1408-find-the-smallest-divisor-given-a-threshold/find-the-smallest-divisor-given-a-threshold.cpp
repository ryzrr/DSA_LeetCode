class Solution {
public:
   int sumByDi(vector<int>& nums, int div){
    long long sum=0;
    int n=nums.size();
    for(int i=0;i<n;i++){
        sum=sum+ceil((double)nums[i]/div);
    }
    return sum;

   }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1;
        int high = *max_element(nums.begin(),nums.end());
        while(low<=high){
            int mid =(low+high)/2;
            int ans= sumByDi(nums,mid);
            if(ans<=threshold){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};