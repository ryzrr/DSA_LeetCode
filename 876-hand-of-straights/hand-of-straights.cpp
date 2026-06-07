class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0)
            return false;
        map<int, int> freq;
        for (auto& it : hand) {
            freq[it]++;
        }
        priority_queue<int, vector<int>, greater<int>> p;
        for (auto& it : freq) {
            p.push(it.first);
        }
        while (!p.empty()) {
            if (freq[p.top()] == 0) {
                p.pop();
                continue;
            }
            int curr = p.top();
            for (int i = 0; i < groupSize; i++) {
                int nexCurr = curr + i;
                if (freq[nexCurr] == 0) {
                    return false;
                }
                freq[nexCurr]--;
            }
        }
        return true;
    }
};