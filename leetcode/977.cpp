class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans(nums.size(), 0);
        int l = 0, r = nums.size()-1;
        int k = r;
        while (r != l) {
            if (abs(nums[r]) > abs(nums[l])) {
                ans[k] = nums[r] * nums[r];
                r--;
            } else {
                ans[k] = nums[l] * nums[l];
                l++;
            }
            k--;
        }
        ans[k] = nums[l] * nums[l];
        return ans;
    }
};