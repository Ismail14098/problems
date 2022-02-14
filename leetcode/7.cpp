class Solution {
public:
    int reverse(int x) {
        vector<int> nums;
        while (x != 0) {
            nums.push_back(x % 10);
            x /= 10;
        }
        long int res = 0;
        for (int i=0; i<nums.size(); i++) {
            res += nums[i]*pow(10, nums.size()-i-1);
        }
        if (res > INT_MAX) return 0;
        if (res < INT_MIN) return 0;
        return res;
    }
};