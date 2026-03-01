class Solution {
public:
    int jump(vector<int>& nums) {
     int jump =0,currIndex=0,farthest=0;
     for(int i=0; i<nums.size()-1;i++){
        farthest= max (farthest,i+nums[i]);
        if(i==currIndex){
            jump++;
            currIndex=farthest;
        }
     }    
     return jump;
    }
};