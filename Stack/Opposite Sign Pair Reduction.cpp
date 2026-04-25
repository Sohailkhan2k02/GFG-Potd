class Solution {
  public:
    vector<int> asteroidCollision(int N, vector<int> &asteroids) {
        // code here
        stack<int> s;
    vector<int> arr;
    for (int i = 0; i < N; i++) {
        if (s.empty() || s.top() < 0 || asteroids[i] > 0) {
            s.push(asteroids[i]);
        }
        while (!s.empty() && s.top() > 0 && asteroids[i] < 0) {
            if (abs(s.top()) > abs(asteroids[i])) {
                s.push(asteroids[i]);
                s.pop();
                break; 
            } else if (abs(s.top()) == abs(asteroids[i])) {
                s.pop();
                break; 
            } else {
                s.pop();
            }
            if (s.empty() || s.top() < 0 || asteroids[i] > 0) {
            s.push(asteroids[i]);
            }
        }
        
    }
    if (!s.empty()) {
        while (!s.empty()) {
            int x = s.top();
            s.pop();
            arr.push_back(x);
        }
    
        reverse(arr.begin(), arr.end());
    
        return arr;
    } else {
       
        return vector<int>();
    }
    }
};
