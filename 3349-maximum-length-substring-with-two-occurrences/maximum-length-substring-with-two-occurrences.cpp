class Solution {
public:
    int maximumLengthSubstring(string s) {
        vector<int> arr(26,0);
        int  n = s.size();
        int left =0 ;
        int  ans = INT_MIN;
        for(int j =0 ;j<n;j++){
            arr[s[j] - 'a']++;
            while(arr[s[j]-'a']>2){
                arr[s[left]-'a']--;
                left++;
            }
        
            ans = max(ans,j-left+1);
        }
        return  ans;
    }
};