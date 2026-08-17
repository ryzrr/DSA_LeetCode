class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
    int smallest = *min_element(nums.begin(), nums.end());
    int largest = *max_element(nums.begin(), nums.end());
    
    vector<int> missing;
    for (int i = smallest; i <= largest; i++) {
        if (numSet.find(i) == numSet.end()) {
            missing.push_back(i);
        }
    }
    
    return missing;
    }
};