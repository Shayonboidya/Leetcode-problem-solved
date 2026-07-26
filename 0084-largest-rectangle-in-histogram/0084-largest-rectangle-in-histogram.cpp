class Solution {
public:
    int largestRectangleArea(vector<int>& v) {
        int n = v.size();
        vector<int>leftSmallest(n,0);
        vector<int>rightsmallest(n,0);
        stack<int>st;

        //left
        for(int i = 0;i < n;i++){
            while (st.size() > 0 && v[st.top()] >= v[i]) st.pop();

            leftSmallest[i] = st.empty()?-1:st.top();

            st.push(i);
            
        }
        while (!st.empty())st.pop();
        
        //right
        for(int i = n-1; i >= 0;i--){
            while (st.size() > 0 && v[st.top()] >= v[i]) st.pop();

            rightsmallest[i] = st.empty()? n:st.top();

            st.push(i);
            
        }
        
        int ans = 0;
        for(int i =0 ;i < n; i++){
            int width = rightsmallest[i] - leftSmallest[i] -1;
            int currectAns = v[i] * width;
            ans = max(ans,currectAns);
        }
        return ans;
    }
};