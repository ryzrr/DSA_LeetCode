class Solution {
public:
    char nextGreatestLetter(vector<char>& lett, char target) {
        for (int i = 0; i < lett.size(); i++) {
            if (lett[i] > target)
                return lett[i];
        }
        return lett[0];
    }
};