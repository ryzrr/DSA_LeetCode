class Solution {
public:
     vector<string>ans;
     void solve(int ind,string &digits, unordered_map<char,string>&mpp,string &temp){
            if(ind>=digits.length()){
                ans.push_back(temp);
                return ;
            }
            char ch = digits[ind];
            string s = mpp[ch];
            for(int i = 0 ; i<s.length();i++){
                temp.push_back(s[i]);
                solve(ind+1,digits,mpp,temp);
                temp.pop_back();
            }
     }
     vector<string> letterCombinations(string digits) {
        if(digits.length()==0) return {};
       unordered_map<char,string> mpp;
       mpp['2'] ="abc";
       mpp['3'] ="def";
       mpp['4'] ="ghi";
       mpp['5'] ="jkl";
       mpp['6'] ="mno";
       mpp['7'] ="pqrs";
       mpp['8'] ="tuv";
       mpp['9'] ="wxyz";
       string temp ="";

       solve(0,digits,mpp,temp);
       return ans; 

    }
};