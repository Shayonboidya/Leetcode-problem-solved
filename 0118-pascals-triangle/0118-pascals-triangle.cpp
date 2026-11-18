class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;

        for (int i = 0; i < numRows; i++) {
            int val = 1;
            vector<int> row;
            for (int j = 0; j <= i; j++) {
                row.push_back(val);
                val = val * (i - j) / (j + 1);
            }
            ans.push_back(row);
        }
        return ans;
    }
};