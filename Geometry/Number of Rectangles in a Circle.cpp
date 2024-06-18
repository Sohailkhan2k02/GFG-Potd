// User function Template for C++

class Solution {
  public:
    int rectanglesInCircle(int radius) {
        // code here
         int rectangleCount = 0; 
        for(int width = 1; width <= radius * 2; width++){
            for(int height = 1; height <= radius * 2; height++){
                if(((width * width) + (height * height)) <= (radius * radius * 4))
                    rectangleCount++;
            }
        }
        return rectangleCount;
    }
};
