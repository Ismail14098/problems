#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

using namespace std;


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(begin(nums), end(nums));
        for (int i=0; i<nums.size(); i++) {
            int l = i+1;
            int r = nums.size()-1;
            if (i > 0 and nums[i] == nums[i-1]) continue;
            while (l<r) {
                int curr = nums[i] + nums[l] + nums[r];
                if (curr>0) {
                    r--;
                } else if (curr<0) {
                    l++;
                } else {
                    result.push_back({nums[i], nums[l], nums[r]});
                    int last_l = nums[l];
                    int last_r = nums[r];
                    while (l < r && last_l == nums[l]) l++;
                    while (l < r && last_r == nums[r]) r--;
                }
            }
        }
        return result;
    }
};

int main() {
    vector<int> a = {-1,-1,0,1,2,-1,-4};
    Solution s;
    auto nums = s.threeSum(a);
    return 0;
}
