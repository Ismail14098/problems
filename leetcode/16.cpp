class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int result = nums[0] + nums[1] + nums[nums.size()-1];
        sort(begin(nums), end(nums));
        for (int i=0; i<nums.size()-2; i++) {
            int l = i+1;
            int r = nums.size()-1;
            while (l<r) {
                int curr = nums[i] + nums[l] + nums[r];
                if (curr>target) {
                    r--;
                } else {
                    l++;
                }
                if (abs(curr-target) < abs(result-target)) {
                    result = curr;
                }
            }
        }
        return result;
    }
};