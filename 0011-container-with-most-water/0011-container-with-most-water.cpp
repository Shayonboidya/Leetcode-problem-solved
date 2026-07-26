class Solution {
public:
    int maxArea(vector<int>& height) {
        int mxwater = 0,st = 0, end = height.size()-1;
        while(st < end){
            int ht = min(height[st], height[end]);
            int wid = end - st;
            mxwater = max(mxwater,ht*wid);
            (height[st] < height[end]) ? st++ : end--;
        }
        return mxwater;
        
    }
};