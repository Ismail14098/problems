class Solution {
public:
    int rob(vector<int>& nums) {
        return max(max(helper(nums.begin(), nums.end()-1), helper(nums.begin()+1, nums.end())), nums[0]);
    }
    
    int helper(vector<int>::iterator start, vector<int>::iterator end) {
        int sum0 = 0, sum1 = 0;
        for (auto i=start; i!=end; i++) {
            int temp = max(sum0+*i, sum1);
            sum0 = sum1;
            sum1 = temp;
        }
        return sum1;
    }
};