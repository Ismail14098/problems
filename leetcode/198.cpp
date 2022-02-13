class Solution {
public:
    int rob(vector<int>& nums) {
        int sum0 = 0, sum1 = 0;
        for (int i=0; i<nums.size(); i++) {
            int temp = max(sum0+nums[i], sum1);
            sum0 = sum1;
            sum1 = temp;
        }
        return sum1;
    }
};