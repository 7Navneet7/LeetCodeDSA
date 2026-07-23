class MedianFinder {
public:
    priority_queue<int,vector<int>>mxh;
    priority_queue<int,vector<int>,greater<int>>mnh;

    MedianFinder() {
        
    }
    
    void addNum(int n) {
        //adding 1st to left heap(max heap)
        mxh.push(n);
        //value constraint
        if(!mnh.empty() && mxh.top()>mnh.top()){
            mnh.push(mxh.top());
            mxh.pop();
        }
        //size constrint
        if(mxh.size()<mnh.size()){
            mxh.push(mnh.top());
            mnh.pop();
        }
        else if(mxh.size()>mnh.size()+1){
            mnh.push(mxh.top());
            mxh.pop();
        }
    }
    
    double findMedian() {
        if(mxh.size()>mnh.size())return mxh.top();
        return (mxh.top()+mnh.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */