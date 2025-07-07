class Solution {
public:
    bool rotateString(string s, string goal) {
        string  concat = s+s;
        if(s.length()!=goal.length()) return false;
        int ind = concat.find(goal);
        if(ind==-1) return false;
        else return true;
    }
};