

class MedianFinder {
public:
    priority_queue<int> left_max;
    priority_queue<int,vector<int>,greater<int>> right_min;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(left_max.empty() || num < left_max.top()){
            left_max.push(num);
        }
        else{
            right_min.push(num);
        }

        // ab  check krenge  kya  sahi mein  oush corret  position hai   yah nhi  
        if(left_max.size() > right_min.size()+1){
            int val=left_max.top();
            left_max.pop();
            right_min.push(val);
        }
        else if(left_max.size() < right_min.size() ){
            left_max.push(right_min.top());
            right_min.pop();

        }
        
    }
    
    double findMedian() {
        if(left_max.size() == right_min.size()){
            double ans;
           return ans = (left_max.top() + right_min.top())/2.0;
        }
        else return left_max.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */