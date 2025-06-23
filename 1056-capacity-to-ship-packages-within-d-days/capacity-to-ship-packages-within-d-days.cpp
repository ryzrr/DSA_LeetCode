class Solution {
public:
int findDays(vector<int>& weights, int cap){
    int days=1; 
    int load=0;
    for(int i =0;i<weights.size();i++){
        if(load+weights[i]>cap){
            days+=1;
            load=weights[i];
        }
        else{
            load+=weights[i];
        }

    }
    return days ;
}
    int shipWithinDays(vector<int>& weights, int d) {
        int low =*max_element(weights.begin(),weights.end());
        int high= accumulate(weights.begin(),weights.end(),0);
        while(low<=high){
            int mid=(low+high)/2;
            int noDays = findDays(weights,mid);
            if(noDays<=d){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};