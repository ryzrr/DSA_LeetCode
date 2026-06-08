class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> countMap;
        for(int num : nums) {
            countMap[num]++;
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        for(auto& it : countMap) {
            int number = it.first;
            int freq = it.second;
            minHeap.push({freq, number});
            if(minHeap.size() > k) {
                minHeap.pop();
            }
        }
        vector<int> result;
        while(!minHeap.empty()) {
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }
        
        return result;
    }
};