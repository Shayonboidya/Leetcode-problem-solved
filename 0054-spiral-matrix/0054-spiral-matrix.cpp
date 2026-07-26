class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        int m = mat.size(),n = mat[0].size();

        vector<int> ans;

        int srow = 0, erow = m-1, scol = 0, ecol = n-1;

        while (srow <= erow && scol <= ecol)
        {
            //top boundarry
            for(int i=scol; i <= ecol;i++){
                ans.push_back(mat[srow][i]);
            }
            //right boundarry
            for(int j=srow+1; j <= erow;j++){
                ans.push_back(mat[j][ecol]);
            }
            //down boundarry
            for(int i=ecol-1; i >= scol;i--){
                if(srow == erow){
                    break;
                }
                ans.push_back(mat[erow][i]);
            }
            //left boundarry
            for(int j =erow-1; j >= srow+1;j--){
                if(scol == ecol){
                    break;
                }
                ans.push_back(mat[j][scol]);
            }
            scol++;srow++;erow--;ecol--;
            /* code */
        }
        return ans;
    }
};