class Solution {
public:
    int noStudent(vector<int> &arr, int pages){
        int student=1;
        long long pagesperstudent=0;
        for(int i=0;i<arr.size();i++){
            if(pagesperstudent+arr[i]<=pages){
                pagesperstudent+=arr[i];
            }
            else{
                student++;
                pagesperstudent=arr[i];
            }
        }
        return student ;
    }
    
    
    int findPages(vector<int> &arr, int k) {
        if (k>arr.size()) return -1;
        int low =*max_element(arr.begin(),arr.end());
        int high=accumulate(arr.begin(),arr.end(),0);
        
        while(low<=high){
            int mid = (low+high)/2;
            int  student=noStudent(arr,mid);
            if(student>k){
                low=mid+1;
            }
            else high=mid-1;   
            
        }
        return low;
    }
    int splitArray(vector<int>& nums, int k) {
        return findPages(nums,k);
    }
};