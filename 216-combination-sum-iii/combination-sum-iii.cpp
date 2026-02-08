class Solution {
public:
    void solve(int ind,int k ,int n, vector<vector<int>>&ans,vector<int>&ds){
        if(ds.size()==k && n==0){
            ans.push_back(ds);
            return;
        }
        if(ds.size()>k || n<0) return;
        for(int i = ind; i<=9;i++){
            ds.push_back(i);
            solve(i+1,k,n-i,ans,ds);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans ;
        vector<int>ds;
        solve(1,k,n,ans,ds);
        return ans;
    }
};