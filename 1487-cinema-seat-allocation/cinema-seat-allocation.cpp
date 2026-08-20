class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedcol) {
        unordered_map<int,unordered_set<int>>mpp;
        for(auto &p :  reservedcol){
            int row = p[0];
            int col = p[1];
            mpp[row].insert(col);
        }
         int count = 0;
        
        
        for (auto& [row, col] : mpp) {
            bool leftFree  = !col.count(2) && !col.count(3) && !col.count(4) && !col.count(5);
            bool rightFree = !col.count(6) && !col.count(7) && !col.count(8) && !col.count(9);
            bool midFree   = !col.count(4) && !col.count(5) && !col.count(6) && !col.count(7);
            
            if (leftFree && rightFree) {
                count += 2;   // dono independent blocks free hain
            } else if (leftFree || rightFree || midFree) {
                count += 1;   // sirf ek block fit ho sakta hai
            }
        }
        
       // baaki (non-reserved) rows ke liye 2 groups har row mein
        count += (n - mpp.size()) * 2;
        
        return count;
        
    }
};