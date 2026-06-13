class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> mp(26,0);
        for(char &ch : tasks ){
            mp[ch -'A']++;
        }
        priority_queue<int>p;
        for(auto &it : mp){
            if(it>0){
                p.push(it);
            }
        }
        int t =0;
        while(!p.empty()){
            vector<int> temp;
            for(int i= 1 ; i <=n+1; i++){
                if(!p.empty()){
                int  freq = p.top();
                freq--;
                p.pop();
                temp.push_back(freq);
                }
            }

            for(int &f : temp){
                if(f>0) p.push(f);
            }
            if(p.empty()) t +=temp.size();
            else  t +=n+1;
        }
        return t;
    }

};