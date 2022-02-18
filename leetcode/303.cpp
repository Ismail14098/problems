class NumArray {
public:
    vector<int> sums;
    NumArray(vector<int>& nums) {
        sums.push_back(nums[0]);
        for (int i=1; i<nums.size(); i++) {
            sums.push_back(sums[i-1]+nums[i]);
        }
    }
    
    int sumRange(int left, int right) {
        if (left == 0) return sums[right];
        return sums[right] - sums[left-1];
    }
};