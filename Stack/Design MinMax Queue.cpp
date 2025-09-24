class SpecialQueue {
    deque<int> mini, maxi;
    vector<int> tmp;
    int idx = 0;
  public:

    void enqueue(int x) {
        // Insert element into the queue
        tmp.push_back(x);
        
        while(!mini.empty() && tmp[mini.back()] > x) mini.pop_back();
        mini.push_back(tmp.size() - 1);
        
        while(!maxi.empty() && tmp[maxi.back()] < x) maxi.pop_back();
        maxi.push_back(tmp.size() - 1);
    }

    void dequeue() {
        // Remove element from the queue
        if(mini.front() == idx) mini.pop_front();
        if(maxi.front() == idx) maxi.pop_front();
        idx++;
    }

    int getFront() {
        // Get front element
        return tmp[idx];
    }

    int getMin() {
        // Get minimum element
        return tmp[mini.front()];
    }

    int getMax() {
        // Get maximum element
        return tmp[maxi.front()];
    }
};
