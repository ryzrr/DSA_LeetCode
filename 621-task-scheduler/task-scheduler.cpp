class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> mpp(26,0);
        for(char &ch : tasks ){
            mpp[ch -'A']++;
        }
        priority_queue<int>p;
        for(auto &it : mpp){
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