
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int pivote = -1;
        int n = nums.size();
        for(int i= n-2;i >= 0;i--){
            if(nums[i] < nums[i+1]){
                pivote = i;
                break;
            }
        }
        if(pivote == -1){
            reverse(nums.begin(),nums.end());
            return;
        }

        for(int i = n-1; i > pivote;i--){
            if(nums[pivote] < nums[i]){
                swap(nums[pivote],nums[i]);
                break;
            }
        }

        int i = pivote+1, j = n-1;
        while(i <= j){
            swap(nums[i],nums[j]);
            i++,j--;
        }
        return;

    }
};