class kQueues {
    vector<int> front;
    vector<int> rear;
    vector<int> arr;
    vector<int> next;
    int freeindex;
  public:
    kQueues(int n, int k) {
        // Initialize your data members
        front.resize(k,-1);
        rear.resize(k,-1);
        next.resize(n,-1);
        arr.resize(n,-1);
        for(int i=0;i<n-1;i++){
            next[i]=i+1;
        }
        freeindex=0;
    }
    void enqueue(int x, int i) {
        // enqueue element x into queue i
        if(freeindex==-1){
            return ;
        }
        int index=freeindex;
        
        freeindex=next[index];
        
        if(front[i]==-1){
            front[i]=index;
            rear[i]=index;
            arr[index]=x;
            next[index]=-1;
        }
        else{
            arr[index]=x;
            next[index]=-1;
            next[rear[i]]=index;
            rear[i]=index;
        }
    }

    int dequeue(int i) {
        // dequeue element from queue i
        
        if(front[i]==-1){
            return -1;
        }
        int temp=arr[front[i]];
        
        int temp2=next[front[i]];
        next[front[i]]=freeindex;
        freeindex=front[i];
        front[i]=temp2;
        if(front[i]==-1){
            rear[i]=-1;
        }
        return temp;
    }

    bool isEmpty(int i) {
        // check if queue i is empty
        if(front[i]!=-1){
            return false;
        }
        return true;
    }
    bool isFull() {
        // check if array is full
        
        if(freeindex==-1){
            return true;
        }
        
        return false;
    }
};
