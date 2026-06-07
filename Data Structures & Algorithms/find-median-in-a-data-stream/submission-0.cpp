class MedianFinder {
    priority_queue<int> pq1;
    priority_queue<int, vector<int>, greater<int>>  pq2;
    
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
         pq1.push(num);
        pq2.push(pq1.top());
        pq1.pop();

        if (pq2.size() > pq1.size()) {
            pq1.push(pq2.top());
            pq2.pop();
        }
    }
    
    double findMedian() {
         if(pq1.size()==pq2.size()){
            int num= pq1.top()+ pq2.top();
            return ((double) num)/2;
        }else{
            return (double) pq1.top();
        }
    }
};
