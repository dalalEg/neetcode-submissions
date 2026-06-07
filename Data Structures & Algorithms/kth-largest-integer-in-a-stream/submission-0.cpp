class KthLargest {
      priority_queue<int, vector<int>, greater<int>> minHeap;
      int k;
    public:
    KthLargest(int k, vector<int>& nums) {
        this->k=k;
      for (int num : nums) {
        if (minHeap.size() < k) {
            minHeap.push(num);
        } else if (num > minHeap.top()) {
            minHeap.pop();
            minHeap.push(num);
        }
        }
         

    }
    
    int add(int val) {
         minHeap.push(val);
        if (minHeap.size() > k) {
            minHeap.pop();
        }
        return minHeap.top();
    }
};
