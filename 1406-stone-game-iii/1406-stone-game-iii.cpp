class Solution {
public:
    int n;
    vector<int>t;
    int solved(int i, vector<int>& v) {
        if (i >= n) {
            return 0;
        }
        if(t[i] != -1){
            return t[i];
        }
        int deff = INT_MIN;
        deff = v[i] - solved(i + 1, v);
        
        if (i + 1 < n) {
            deff = max(deff, v[i] + v[i + 1] - solved(i + 2, v));
        }
        if (i + 2 < n) {
            deff = max(deff, v[i] + v[i + 1] + v[i + 2] - solved(i + 3, v));
        }
        return t[i] = deff;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        n = stoneValue.size();
        t.resize(n+1,-1);
        int res = solved(0, stoneValue);
        if (res > 0)
            return "Alice";
        else if (res < 0)
            return "Bob";

        return "Tie";
    }
};