class Solution {
public:
    int maxProduct(int n) {
      
      string s=to_string(n);
      sort(s.begin(),s.end());
        int p = s.size();
        return (s[p-1]-'0')*(s[p-2]-'0') ;
    }
};