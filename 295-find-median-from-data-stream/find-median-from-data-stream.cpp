class MedianFinder {
public:
    MedianFinder() {}
    vector<int> nums;

    void addNum(int num) {
       auto it = lower_bound(nums.begin(), nums.end(), num);
       nums.insert(it, num);
                                                         
    }

    double findMedian() {
        int n = nums.size();
        if(n % 2 == 1){
            return nums[n/2];
        }
        return (nums[n/2] + nums[n/2 - 1])/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */