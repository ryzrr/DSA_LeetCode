class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int low =0 ,high=n-1;
        while(low<=high){
            int mid =(low+high)/2;
            int missingNumber = arr[mid]-(mid+1);
            if(missingNumber<k) low=mid+1;
            else high=mid-1;
        }
         return low+k; // or return high+1+K  both are same as explainby striver;  
    }
};