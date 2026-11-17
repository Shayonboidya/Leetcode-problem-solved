class Solution {
public:
    int findLeft_most(vector<int>& nums, int target, int n) {
        int r = nums.size() - 1;
        int l = 0;
        int left_mostIdx = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (target < nums[mid]) {
                r = mid - 1;
            } else if (nums[mid] < target) {
                l = mid + 1;
            } else {
               left_mostIdx = mid;
                r = mid -1;
            }
        }
        return left_mostIdx;
    }

    int findRight_most(vector<int>& nums, int target, int n) {
        int r = nums.size() - 1;
        int l = 0;
        int right_mostIdx = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (target < nums[mid]) {
                r = mid - 1;
            } else if (nums[mid] < target) {
                l = mid + 1;
            } else {
               right_mostIdx = mid;
                l = mid +1;
            }
        }
        return right_mostIdx;
    }


    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int left_most = findLeft_most(nums,target, n);
        int right_most = findRight_most(nums,target, n);

        return {left_most,right_most};
    }
};